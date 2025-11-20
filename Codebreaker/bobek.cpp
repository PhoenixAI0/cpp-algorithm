#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; ll m; cin >> n >> m;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    int L = n/2, R = n-L;
    vector<ll> l, r;
    for (int i = 0; i < (1<<L); i++) {
        ll s = 0;
        for (int j = 0; j < L; j++) if (i&(1<<j)) s += a[j];
        if (s <= m) l.push_back(s);
    }
    for (int i = 0; i < (1<<R); i++) {
        ll s = 0;
        for (int j = 0; j < R; j++) if (i&(1<<j)) s += a[L+j];
        if (s <= m) r.push_back(s);
    }
    sort(r.begin(), r.end());
    ll ans = 0;
    for (auto& x : l) ans += upper_bound(r.begin(), r.end(), m-x)-r.begin();
    cout << ans << "\n";
}
