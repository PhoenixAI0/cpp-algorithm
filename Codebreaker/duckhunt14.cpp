#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    ll X, Y;
    cin >> X >> Y;

    sort(b.begin(), b.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (X == 0) ans += m;
            continue;
        }
        ll Min = (X + a[i] - 1) / a[i];
        ll Max = Y / a[i];
        if (Min > Max) continue;
        ans += upper_bound(b.begin(), b.end(), Max) - lower_bound(b.begin(), b.end(), Min);
    }

    cout << ans << "\n";
}
