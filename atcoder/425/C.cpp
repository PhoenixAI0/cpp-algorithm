#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(2*n);
    for (ll i = 0; i < 2*n; i++) b[i] = a[i%n];
    vector<ll> p(2*n+1);
    for (ll i = 0; i < 2*n; i++) p[i+1] = p[i]+b[i];
    ll s = 0;
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll c;
            cin >> c;
            s = (s+c)%n;
        } else {
            ll l, r;
            cin >> l >> r;
            cout << p[s+l-1+r-l+1]-p[s+l-1] << '\n';
        }
    }
}
