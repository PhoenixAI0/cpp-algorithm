#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(M, vector<int>(N));
    for (auto& x : a) for (int& y : x) cin >> y;

    vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
    for (int i = 0; i < M; i++) dp[i][0] = a[i][0];
    for (int j = 1; j < N; j++) {
        for (int i = 0; i < M; i++) {
            int prev = (i - 1 + M) % M;
            dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j]);
            dp[i][j] = min(dp[i][j], dp[prev][j-1] + a[i][j]);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < M; i++) ans = min(ans, dp[i][N-1]);
    cout << ans << "\n";
}
