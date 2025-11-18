#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> c = {1, 2, 3, 5, 10, 20};
    vector<int> a(6);
    for (int i = 0; i < 6; i++) cin >> a[i];

    vector<bool> dp(1001, false);
    dp[0] = true;
    for (int i = 0; i < 6; i++) {
        int v = c[i], x = a[i];
        if (x == 0) continue;
        for (int k = 1; x > 0; k *= 2) {
            int n = min(x, k);
            for (int j = 1000; j >= v * n; j--) if (dp[j - v * n]) dp[j] = true;
            x -= n;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) if (dp[i]) ans++;
    cout << "Total=" << ans << "\n";
}
