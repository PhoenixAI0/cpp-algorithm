#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) for (int j = m; j >= a[i]; j--) dp[j] += dp[j - a[i]];
    cout << dp[m];
}
