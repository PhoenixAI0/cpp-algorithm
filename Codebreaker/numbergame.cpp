#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), c(n);
    for (auto &v : a) cin >> v;
    for (auto &v : b) cin >> v;
    for (auto &v : c) cin >> v;

    sort(c.begin(), c.end());

    ll r = a[0] * b[0] + c[0];
    ll d = abs(r - x);

    for (auto i : a) {
        for (auto j : b) {
            ll p = i * j;
            auto k = lower_bound(c.begin(), c.end(), x - p);

            if (k != c.end()) {
                ll s = p + *k;
                ll e = abs(s - x);
                if (e < d || (e == d && s > r)) {
                    d = e;
                    r = s;
                }
            }
            if (k != c.begin()) {
                ll s = p + *(k - 1);
                ll e = abs(s - x);
                if (e < d || (e == d && s > r)) {
                    d = e;
                    r = s;
                }
            }
        }
    }
    cout << r;
}