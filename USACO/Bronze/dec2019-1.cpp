#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n; cin >> k >> n;
    vector<vector<int>> rankings(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rankings[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            bool consistent = true;
            for (int session = 0; session < k; session++) {
                int pos_i = 0, pos_j = 0;
                for (int pos = 0; pos < n; pos++) {
                    if (rankings[session][pos] == i) pos_i = pos;
                    if (rankings[session][pos] == j) pos_j = pos;
                }
                if (pos_i > pos_j) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) ans++;
        }
    }
    cout << ans << "\n";
}