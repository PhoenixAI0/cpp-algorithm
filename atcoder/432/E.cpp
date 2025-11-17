#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, y; cin >> x >> y;
            a[x-1] = y;
        } else {
            long long ans = 0; int l, r; cin >> l >> r;
            for (int z : a) ans += max(l, min(r, z));
            cout << ans << "\n";
        }
    }
}
