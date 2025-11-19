#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;

    vector<vector<int>> nxt(n + 1, vector<int>(30, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int b = 0; b < 30; b++) nxt[i][b] = nxt[i + 1][b];
        for (int b = 0; b < 30; b++) if ((a[i] >> b) & 1) nxt[i][b] = i;
    }

    vector<vector<int>> dp(n + 1);
    dp[0].push_back(0);

    for (int i = 0; i < n; i++) {
        if (dp[i].empty()) continue;
        sort(dp[i].begin(), dp[i].end());
        dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());

        int p = i, v = 0;
        while (p < n) {
            v |= a[p];
            int end = n;
            for (int b = 0; b < 30; b++) {
                if (!((v >> b) & 1)) end = min(end, nxt[p + 1][b]);
            }
            for (int k = p + 1; k <= end; k++) {
                for (int x : dp[i]) dp[k].push_back(x ^ v);
            }
            p = end;
        }
        vector<int>().swap(dp[i]);
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
}