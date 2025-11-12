https://atcoder.jp/contests/abc430/tasks/abc430_e
// O(n + m) solution
// Reflections: 
// 1. Find b in aa rather than rolling string a for efficiency.
// 2. KMP algorithm over find for efficiency.

#include <bits/stdc++.h>
using namespace std;

int kmp(const string& text, const string& pat) {
    int n = (int)text.size(), m = (int)pat.size();
    vector<int> lps(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pat[i] != pat[j]) j = lps[j - 1];
        if (pat[i] == pat[j]) ++j;
        lps[i] = j;
    }
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pat[j]) j = lps[j - 1];
        if (text[i] == pat[j]) ++j;
        if (j == m) return i - m + 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        string a, b; 
        cin >> a >> b;
        string aa = a + a;
        int pos = kmp(aa, b);
        cout << ((pos != -1 && pos < a.size()) ? pos : -1) << '\n';
    }
}