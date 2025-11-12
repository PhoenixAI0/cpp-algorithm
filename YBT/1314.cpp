#include <bits/stdc++.h>
using namespace std;

static const int KNIGHT_MOVES[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int cx, cy;
    cin >> n >> m >> cx >> cy;
    vector<vector<bool>> controlled(n+1, vector<bool>(m+1, false));

    if (cx >= 0 && cx <= n && cy >= 0 && cy <= m) {
        controlled[cx][cy] = true;
    }

    for (auto &move : KNIGHT_MOVES) {
        int nx = cx + move[0];
        int ny = cy + move[1];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            controlled[nx][ny] = true;
        }
    }

    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0LL));

    if (!controlled[0][0]) {
        dp[0][0] = 1;
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
            if (x == 0 && y == 0) continue;

            if (controlled[x][y]) {
                dp[x][y] = 0;
                continue;
            }

            long long fromLeft = 0, fromUp = 0;
            if (x - 1 >= 0) fromLeft = dp[x - 1][y];
            if (y - 1 >= 0) fromUp = dp[x][y - 1];

            dp[x][y] = fromLeft + fromUp;
        }
    }

    cout << dp[n][m] << "\n";
}