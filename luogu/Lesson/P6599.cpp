#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
typedef unsigned long long ull;
const long long MOD = 1'000'000'007LL;

long long calc(long long e){
    long long base = 2, res = 1;
    while(e){
        if(e & 1) res = (lll)res * base % MOD;
        base = (lll)base * base % MOD;
        e >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    while(T--){
        ull n, l;
        cin >> n >> l;
        if(n == 1ULL){
            cout << 0 << '\n';
            continue;
        }
        int h = 63 - __builtin_clzll(n);
        ll M = (calc(h + 1) - 1 + MOD) % MOD;
        ll xy = ( (lll)((l / 2) % MOD) * ((l / 2) % MOD) ) % MOD;
        ll ans = ( (lll)xy * M ) % MOD;
        cout << (ll)ans << '\n';
    }
}