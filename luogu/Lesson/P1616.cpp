#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    vector<long long> dp(t + 1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = a[i]; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[t] << "\n";
}
