#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + (s[i] == 'a');

    vector<int> T(n + 1, 0);
    for (int k = 0; k <= n; k++) T[k] = k - prefix[k];

    long long ans = 0;
    int p1 = 1;
    int p2 = 0;

    for (int i = 0; i < n; ++i) {
        if (p1 < i + 1) p1 = i + 1;
        int need = prefix[i] + a;
        while (p1 <= n && prefix[p1] < need) ++p1;

        int x = T[i] + b - 1;
        while (p2 + 1 <= n && T[p2 + 1] <= x) ++p2;

        if (p1 <= p2) ans += (long long)(p2 - p1 + 1);
    }

    cout << ans;
}