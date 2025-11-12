#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000000;
vector<bool> is_prime(MAXN + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sieve();

    int limit = (n == 32 ? 0xFFFFFFFF : (1 << n));
    int comb  = (k == 0 ? 0 : ((1 << k) - 1));

    int cnt = 0;
    while (comb < limit) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (comb & (1 << i)) sum += a[i];

        if (is_prime[sum]) cnt++;

        int c = comb & -comb;
        int r = comb + c;
        comb = (((r ^ comb) >> 2) / c) | r;
    }
    cout << cnt << "\n";
}