#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n; cin >> x >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<bool> used(n, false);
    int q; cin >> q;
    while (q--) {
        int i; cin >> i;
        i--;
        if (used[i]) {
            used[i] = false;
            x -= w[i];
        } else {
            used[i] = true;
            x += w[i];
        }
        cout << x << "\n";
    }
}
