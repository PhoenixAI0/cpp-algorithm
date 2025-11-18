#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ll a, b; cin >> a >> b;
    ll x = gcd(a, b);
    cout << x << " " << (ll)(a * b / x) << "\n";
}
