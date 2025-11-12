#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string padHex(const string &s) {
    string res = s;
    while (res.size() < 4) {
        res = "0" + res;
    }
    return res;
}

vector<string> split(const string &s, char delimiter) {
    vector<string> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

int main(){
    string ipv6;
    getline(cin, ipv6);

    vector<string> groups;
    size_t pos = ipv6.find("::");
    if (pos != string::npos) {
        string left = ipv6.substr(0, pos);
        string right = ipv6.substr(pos + 2);
        vector<string> leftGroups, rightGroups;
        if (!left.empty()) {
            leftGroups = split(left, ':');
        }
        if (!right.empty()) {
            rightGroups = split(right, ':');
        }
        int missing = 8 - (leftGroups.size() + rightGroups.size());
        for (const auto &g : leftGroups) {
            groups.push_back(g);
        }
        for (int i = 0; i < missing; i++) {
            groups.push_back("0");
        }
        for (const auto &g : rightGroups) {
            groups.push_back(g);
        }
    } else {
        groups = split(ipv6, ':');
    }

    string binaryResult;
    for (const auto &group : groups){
        string fullGroup = padHex(group);
        for (char c : fullGroup) {
            int num;
            if(c >= '0' && c <= '9')
                num = c - '0';
            else if(c >= 'A' && c <= 'F')
                num = c - 'A' + 10;
            else
                num = c - 'a' + 10;
            for (int i = 3; i >= 0; i--) {
                binaryResult.push_back(((num >> i) & 1) ? '1' : '0');
            }
        }
    }
    
    cout << binaryResult;
}