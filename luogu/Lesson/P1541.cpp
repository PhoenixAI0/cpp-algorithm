#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    
    int a=0, b=0, c=0, d=0;
    for (int i = 0; i < m; i++) {
        int x; cin >> x; 
        if (x == 1) a++;
        else if (x == 2) b++;
        else if (x == 3) c++;
        else d++;
    }

    vector<vector<vector<vector<int>>>> dp(a+1, vector<vector<vector<int>>>(b+1, vector<vector<int>>(c+1, vector<int>(d+1, INT_MIN))));
    dp[0][0][0][0] = grid[0];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                for (int l = 0; l <= d; l++) {
                    int pos = i*1 + j*2 + k*3 + l*4;
                    int best = -1;
                    if (i > 0) best = max(best, dp[i-1][j][k][l] + grid[pos]);
                    if (j > 0) best = max(best, dp[i][j-1][k][l] + grid[pos]);
                    if (k > 0) best = max(best, dp[i][j][k-1][l] + grid[pos]);
                    if (l > 0) best = max(best, dp[i][j][k][l-1] + grid[pos]);
                    if (best != -1) dp[i][j][k][l] = best;
                }
            }
        }
    }
    
    cout << dp[a][b][c][d] << "\n";
}