#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, s, t;
        cin >> n >> s >> t;
        vector<ull> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        (s == t) ? cout << "0\n" : cout << (2ULL * (a[s] | a[t])) << "\n";
    }
}