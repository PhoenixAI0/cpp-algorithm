#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    map<char, int> freq;
    for (char c : S) {
        freq[c]++;
    }
    
    for (auto& p : freq) {
        if (p.second == 1) {
            cout << p.first << endl;
            break;
        }
    }
}
