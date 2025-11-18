#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> p;
    vector<bool> b(n);
    b[0] = b[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!b[i]) p.push_back(i);
        for (int j = 0; j < p.size() && i * p[j] <= n; j++) {
            b[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }

    while (q--) {
        int k; cin >> k;
        cout << p[k - 1] << '\n';
    }
}
