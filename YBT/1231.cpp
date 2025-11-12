#include <bits/stdc++.h>
using namespace std;

string solve(string n, int k) {
    string result = "";
    for (char digit : n) {
        while (!result.empty() && result.back() > digit && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }

    while (k > 0) {
        result.pop_back();
        k--;
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    if (result.empty()) {
        result = "0";
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string n; int k; cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}
