#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    vector<vector<char>> blocked(n + 1, vector<char>(m + 1, 0));

    auto block = [&](long long x, long long y) {
        if (0 <= x && x <= n && 0 <= y && y <= m) blocked[x][y] = 1;
    };

    block(hx, hy);
    const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    for (int k = 0; k < 8; ++k) block(hx + dx[k], hy + dy[k]);

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    if (!blocked[0][0]) dp[0][0] = 1;
    for (long long i = 0; i <= n; ++i) {
        for (long long j = 0; j <= m; ++j) {
            if (blocked[i][j]) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[n][m] << '\n';
}
