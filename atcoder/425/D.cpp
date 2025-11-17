#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<bool> a(h * w, false), u(h * w);
    vector<int> c(h * w);
    vector<int> q, qq, t;

    const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') {
                int id = i * w + j;
                a[id] = true;
                q.push_back(id);
            }
        }
    }

    long long ans = q.size();

    while (!q.empty()) {
        t.clear();

        for (int id : q) {
            int x = id / w, y = id % w;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                int v = nx * w + ny;
                if (a[v]) continue;
                if (++c[v] == 1 && !u[v]) {
                    u[v] = 1;
                    t.push_back(v);
                }
            }
        }

        qq.clear();
        for (int x : t) {
            u[x] = 0;
            if (c[x] == 1) {
                a[x] = 0;
                qq.push_back(x);
                ans++;
            }
        }
        q.swap(qq);
    }

    cout << ans << "\n";
}
