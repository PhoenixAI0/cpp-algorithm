#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes;

void sieve(int n) {
    if (n < 2) return;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                if (j > n) break;
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    sieve(n);
    int ans = 0;
    ll sum = 0;
    for (int p : primes) {
        if (sum + p <= n) {
            sum += p;
            cout << p << "\n";
            ans++;
        } else {
            break;
        }
    }
    cout << ans << "\n";
}