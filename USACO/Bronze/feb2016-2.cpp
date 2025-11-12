#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            cur += a[j] * ((j - i + n) % n);
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
