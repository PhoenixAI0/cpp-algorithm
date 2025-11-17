#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll Min = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll tmp; cin >> tmp; a[i] = tmp; Min = min(tmp, Min);
    }
    ll ans = 0;
    for (ll num : a) {
        ll diff = (num - Min) * y;
        if (diff % (y - x) == 0 && diff / (y - x) <= num) {
            ans += num - (diff / (y - x));
        } else {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << ans << "\n";
}
