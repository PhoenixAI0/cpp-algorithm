#include <bits/stdc++.h>
using namespace std;

static const int M = 12345;
static const long long BIGMOD = 2LL * M;

long long modPow(long long base, int exp, long long modVal) {
    long long result = 1 % modVal;
    base %= modVal;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modVal;
        base = (base * base) % modVal;
        exp >>= 1;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if(N == 1) {
        cout << 8 % M << "\n";
        return 0;
    }

    long long p10 = modPow(10, N-1, BIGMOD);
    long long p8  = modPow(8,  N-1, BIGMOD);
    long long s = (9LL * p10 + 7LL * p8) % BIGMOD;

    if (s % 2 != 0) {
        s += BIGMOD;
    }
    s /= 2;

    long long ans = s % M;
    cout << ans << "\n";
    return 0;
}