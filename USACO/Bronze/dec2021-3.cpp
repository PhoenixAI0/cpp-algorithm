#include <bits/stdc++.h>
using namespace std;

// We'll store paths counts in 64-bit integers (long long)
// to avoid overflow for large path counts.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }

        // dp[r][c][d][k] = number of ways to reach (r, c)
        // with last move direction = d, having used k direction changes.
        // d = 0 => down, 1 => right, 2 => "no direction yet" (only for the start)
        static long long dp[51][51][3][4];
        // We will reset dp for each test case
        memset(dp, 0, sizeof(dp));

        // Initialize
        dp[0][0][2][0] = 1; // Start at (0,0), no direction yet, 0 changes used

        // A quick lambda to check if a cell is valid and not blocked
        auto valid = [&](int r, int c) {
            if (r < 0 || r >= N || c < 0 || c >= N) return false;
            if (grid[r][c] == 'H') return false;
            return true;
        };

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Skip blocked cells in case we do partial checks
                if (grid[r][c] == 'H') continue;

                for (int d = 0; d < 3; d++) {
                    for (int used = 0; used <= K; used++) {
                        long long ways = dp[r][c][d][used];
                        if (ways == 0) continue;

                        // Try to go DOWN => next cell is (r+1, c)
                        if (valid(r+1, c)) {
                            if (d == 2 || d == 0) {
                                // Same direction if d==0 or no direction yet
                                dp[r+1][c][0][used] += ways;
                            } else if (d == 1) {
                                // direction was right, now down => change
                                if (used < K) {
                                    dp[r+1][c][0][used+1] += ways;
                                }
                            }
                        }

                        // Try to go RIGHT => next cell is (r, c+1)
                        if (valid(r, c+1)) {
                            if (d == 2 || d == 1) {
                                // Same direction if d==1 or no direction yet
                                dp[r][c+1][1][used] += ways;
                            } else if (d == 0) {
                                // direction was down, now right => change
                                if (used < K) {
                                    dp[r][c+1][1][used+1] += ways;
                                }
                            }
                        }
                    }
                }
            }
        }

        // Sum up all ways to reach (N-1, N-1) with directions = down or right
        long long answer = 0;
        for (int d = 0; d < 2; d++) {
            for (int used = 0; used <= K; used++) {
                answer += dp[N-1][N-1][d][used];
            }
        }

        cout << answer << "\n";
    }

    return 0;
}