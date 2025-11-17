#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> A[i];

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + A[i];

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}
