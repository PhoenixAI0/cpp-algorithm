#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<long long> f(n + 1, 0), pref(n + 1, 0);
    f[1] = 1;
    pref[1] = 1;
    for (int k = 2; k <= n; ++k) {
        f[k] = 1 + pref[k / 2];
        pref[k] = pref[k - 1] + f[k];
    }

    cout << f[n];
}
