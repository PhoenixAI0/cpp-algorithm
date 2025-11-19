#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; int m; cin >> n >> m;
    vector<ll> a(m);
    ll r = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    ll l = 1;
    while (l < r) {
        ll k = l + (r - l) / 2;
        ll c = 0;
        for (ll x : a)
            c += (x + k - 1) / k;

        if (c <= n) r = k;
        else l = k + 1;
    }
    cout << l << "\n";
}