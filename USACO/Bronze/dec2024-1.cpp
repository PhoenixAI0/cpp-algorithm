#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int isect(int a, int b, int c, int d) {
    int lb = max(a, c);
    int ub = min(b, d);
    return max(0, ub - lb + 1);
}

int solve(int n) {
    int is = 5, ie = 49;
    int tp = 1;
    int ans = 0;
    while (tp < 100000000) {
        tp *= 10;
        is += 4 * tp;
        ie = 5 * tp - 1;
        ans += isect(is, ie, 2, n);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}