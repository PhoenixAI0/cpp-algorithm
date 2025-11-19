#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] > l) l = a[i];
        ll v = a[i] + b[i] * n;
        if (v > r) r = v;
    }
    ll x = r;
    vector<int> c(n);
    while (l <= r) {
        ll m = l + (r - l) / 2;
        fill(c.begin(), c.end(), 0);
        for (int i = 0; i < n; ++i) {
            ll d = (b[i] ? (m - a[i]) / b[i] : n);
            if (d >= n) d = n - 1;
            c[d]++;
        }
        bool f = 1;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += c[i];
            if (s > i + 1) { f = 0; break; }
        }
        if (f) {
            x = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << x << "\n";
}