#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000009;

int main() {
    ll A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    ll ans = A % MOD;
    ans = (ans * (B % MOD)) % MOD;
    ans = (ans * (C % MOD)) % MOD;
    ans = (ans * (D % MOD)) % MOD;
    ans = (ans * (E % MOD)) % MOD;
    cout << ans << "\n";
}
