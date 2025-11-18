#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(i + 1);
        dp[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int x = (j != i ? dp[i-1][j] + a[i][j] : INT_MIN);
            int y = (j != 0 ? dp[i-1][j-1] + a[i][j] : INT_MIN);
            dp[i][j] = max(x, y);
        }
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end());
}
