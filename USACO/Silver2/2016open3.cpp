#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            parent[py] = px;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, char>>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        adj[a].push_back({b, type});
        adj[b].push_back({a, type});
    }
    
    vector<int> color(n + 1, -1);
    int components = 0;
    bool possible = true;
    
    function<bool(int, int)> dfs = [&](int u, int c) -> bool {
        color[u] = c;
        for (auto [v, type] : adj[u]) {
            int next_color;
            if (type == 'S') {
                next_color = c;
            } else {
                next_color = 1 - c;
            }
            
            if (color[v] == -1) {
                if (!dfs(v, next_color)) return false;
            } else if (color[v] != next_color) {
                return false;
            }
        }
        return true;
    };
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            components++;
            if (!dfs(i, 0)) {
                possible = false;
                break;
            }
        }
    }
    
    if (!possible) {
        cout << "0" << endl;
    } else {
        string result = "1";
        for (int i = 0; i < components; i++) {
            result += "0";
        }
        cout << result << endl;
    }
}
