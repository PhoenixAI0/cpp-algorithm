#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> g(n + 1);
    vector<bool> vis(n + 1, false);
    queue<int> q;
    vector<pair<int, int>> p(n + 1);

    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        p[i] = {a, b};
    }

    for (int i = 1; i <= n; i++) {
        int a = p[i].first;
        int b = p[i].second;
        if (a == 0 && b == 0) {
            vis[i] = true;
            q.push(i);
        } else {
            if (a != 0) g[a].push_back(i);
            if (b != 0) g[b].push_back(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (vis[i]) ans++;

    cout << ans << '\n';
}