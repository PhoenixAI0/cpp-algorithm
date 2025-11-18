#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    vector<int> dp(t + 1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[t] << "\n";
}
