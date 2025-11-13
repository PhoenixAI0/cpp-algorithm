#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0)); dp[0][0] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k <= min(a[i], m - j); k++) dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]) % 1000007;
    cout << dp[n][m] << "\n";
}
