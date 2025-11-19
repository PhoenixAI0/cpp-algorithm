#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int h, w; cin >> h >> w;
        vector<string> s(h);
        for (auto& x : s) cin >> x;
        int ans = 0;

        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w - 1; j++) {
                if (s[i][j] == '#' && s[i][j+1] == '#' && s[i+1][j] == '#' && s[i+1][j+1] == '#') {
                    ans++;
                    s[i+1][j+1] = '.';
                }
            }
        }
        cout << ans << '\n';
    }
}
