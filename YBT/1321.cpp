#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int s;
    cin >> n >> s;

    string result = "";
    for (char digit : n) {
        while (!result.empty() && result.back() > digit && s > 0) {
            result.pop_back();
            s--;
        }
        result.push_back(digit);
    }

    while (s > 0) {
        result.pop_back();
        s--;
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    if (result.empty()) {
        result = "0";
    }

    cout << result << "\n";
}