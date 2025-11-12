#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Constants
const int MOD = 998244353;

// Function to compute a^b mod MOD
ll power_mod_func(ll a, ll b, ll mod_val){
    ll res = 1;
    a %= mod_val;
    while(b > 0){
        if(b & 1){
            res = res * a % mod_val;
        }
        a = a * a % mod_val;
        b >>= 1;
    }
    return res;
}

// Function to compute factorial and inverse factorial
pair<vector<ll>, vector<ll>> compute_factorials(int n, int mod_val){
    vector<ll> fact(n+1, 1);
    for(int i=1; i<=n; i++) fact[i] = fact[i-1] * i % mod_val;
    vector<ll> inv_fact(n+1, 1);
    inv_fact[n] = power_mod_func(fact[n], mod_val-2, mod_val);
    for(int i=n-1; i>=0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % mod_val;
    return {fact, inv_fact};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    // Step 1: Compute number of digits for each number
    vector<int> d(N+1, 1);
    for(int i=1; i<=N; i++){
        if(i >= 100000){
            d[i] = 6;
        }
        else{
            int cnt = 0;
            int num = i;
            if(num == 0) cnt = 1;
            while(num > 0){
                cnt++;
                num /=10;
            }
            d[i] = max(cnt, 1);
        }
    }

    // Step 2: Compute factorial and inverse factorial
    auto [fact, inv_fact] = compute_factorials(N, MOD);

    // Step 3: Precompute powers of 10 up to 6 digits
    vector<ll> pow10(7, 1);
    for(int i=1; i<=6; i++) pow10[i] = pow10[i-1] *10 % MOD;

    // Step 4: Precompute (1 + 10^{d_y}) for each y
    vector<ll> one_plus_pow(N+1, 1);
    for(int y=1; y<=N; y++) one_plus_pow[y] = (1 + pow10[d[y]]) % MOD;

    // Step 5: Compute the product of (1 +10^{d_y}) for all y
    vector<ll> prefix_prod(N+1, 1);
    for(int y=1; y<=N; y++) prefix_prod[y] = prefix_prod[y-1] * one_plus_pow[y] % MOD;

    // Step 6: Compute the total product
    ll total_prod = prefix_prod[N];

    // Step 7: For each x, compute product(1 +10^{d_y}) / (1 +10^{d_x})
    // To avoid division, multiply by inverse
    // Precompute inverses of (1 +10^{d_y})
    vector<ll> inv_one_plus_pow(N+1, 1);
    for(int y=1; y<=N; y++) inv_one_plus_pow[y] = power_mod_func(one_plus_pow[y], MOD-2, MOD);

    // Step 8: Compute the sum over all x
    ll sum_x =0;
    for(int x=1; x<=N; x++){
        ll partial_prod = total_prod * inv_one_plus_pow[x] % MOD;
        sum_x = (sum_x + (x * partial_prod) % MOD) % MOD;
    }

    // Step 9: Multiply by (N-1)! to get the final answer
    ll answer = (fact[N-1] * sum_x) % MOD;

    cout << answer;
}