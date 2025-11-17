#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    for (int &x : h) cin >> x;

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k; cin >> k; k--;
            swap(h[k], h[k + 1]);
        } else {
            int k; cin >> k; int ans = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (h[i] < k) {
                    ans = i + 1;
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
}
