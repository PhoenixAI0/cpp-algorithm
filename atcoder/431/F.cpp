#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    int n, D;
    cin >> n >> D;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(a.begin(), a.end(), a[i - 1] - D) - a.begin();
        ans = ans * (i - j) % MOD;
    }

    vector<int> cnts;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        cnts.push_back(j - i);
        i = j;
    }

    vector<ll> x(n + 1, 1), y(n + 1, 1);
    for (int i = 1; i <= n; i++) x[i] = x[i - 1] * i % MOD;
    y[n] = modpow(x[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) y[i] = y[i + 1] * (i + 1) % MOD;

    for (int c : cnts) ans = ans * y[c] % MOD;

    cout << ans << "\n";
}
