#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    int n; cin >> n;
    map<int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (m.find(a) == m.end()) {
            m[a] = b;
        } else {
            if (m[a] != b) {
                ans++;
                m[a] = b;
            }
        }
    }
    cout << ans << "\n";
}