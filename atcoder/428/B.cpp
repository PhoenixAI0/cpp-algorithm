#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; string s;
    cin >> n >> k >> s;
    map<string, int> freq;
    for (int i = 0; i < n - k + 1; i++) {
        freq[s.substr(i, k)]++;
    }
    int max = 0;
    for (auto [str, f] : freq) {
        if (f > max) max = f;
    }
    vector<string> ans;
    for (auto [str, f] : freq) {
        if (f == max) ans.push_back(str);
    }
    sort(ans.begin(), ans.end());
    cout << max << '\n';
    for (const string& str : ans) cout << str << ' ';
    cout << '\n';
}
