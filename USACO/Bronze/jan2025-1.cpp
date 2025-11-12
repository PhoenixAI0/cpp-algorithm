#include <bits/stdc++.h>
using namespace std;


inline bool ok(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<string> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<vector<bool>> f(n, vector<bool>(n, false));
        vector<vector<int>> m(n, vector<int>(n, -1));
        vector<vector<bool>> s(n, vector<bool>(n, false));

        bool bad = false;
        long long cnt = 0;

        
        auto add = [&](int x, int y) {
            if (!f[x][y]) {
                f[x][y] = true;
                cnt++;
            }
        };

        
        auto link = [&](int x, int y, int x2, int y2) {
            if (s[x2][y2]) {
                bad = true;
                return;
            }
            if (m[x][y] != -1 && m[x][y] != x2 * n + y2) {
                bad = true;
                return;
            }
            m[x][y] = x2 * n + y2;
            s[x2][y2] = true;
        };

        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (p[x][y] == 'B') {
                    int x0 = x - b, y0 = y - a;
                    if (!ok(x0, y0, n)) {
                        bad = true;
                        break;
                    }
                    
                    add(x, y);
                    add(x0, y0);
                    link(x0, y0, x, y);
                }
            }
            if (bad) break;
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }

        
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (p[x][y] == 'G' && !g[x][y]) {
                    int x2 = x + b, y2 = y + a;
                    if (ok(x2, y2, n) && p[x2][y2] == 'G' && !g[x2][y2]) {
                        add(x, y);
                        link(x, y, x2, y2);
                        if (bad) break;
                        g[x][y] = true;
                        g[x2][y2] = true;
                    }
                }
            }
            if (bad) break;
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }

        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (p[x][y] == 'G' && !g[x][y]) {
                    int x0 = x - b, y0 = y - a;
                    if (ok(x0, y0, n) && f[x0][y0] && (m[x0][y0] == -1 || m[x0][y0] == x * n + y)) {
                        link(x0, y0, x, y);
                    } else {
                        add(x, y);
                    }
                }
            }
            if (bad) break;
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }

        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (p[x][y] == 'W') {
                    if (f[x][y] || s[x][y]) {
                        bad = true;
                        break;
                    }
                }
            }
            if (bad) break;
        }
        if (bad) {
            cout << -1 << "\n";
        } else {
            cout << cnt << "\n";
        }
    }
}