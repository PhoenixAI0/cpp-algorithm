#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    map<ll, ll> m;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        m[v]++;
        ans += v;
    }

    cout << ans << '\n';

    while (q--) {
        ll l, r, x; cin >> l >> r >> x;

        auto it = m.lower_bound(l);
        ll a = 0;

        while (it != m.end() && it->first <= r) {
            ans -= it->first * it->second;
            a += it->second;
            it = m.erase(it);
        }

        ans += x * a;
        m[x] += a;

        cout << ans << '\n';
    }
}
