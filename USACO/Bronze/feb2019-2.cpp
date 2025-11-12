#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

void solve(int n, vector<pair<int, int>>& v) {
    // Create adjacency list
    vector<vector<int>> adj(n + 1);
    for (auto& p : v) {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }
    
    // For each vertex
    for (int i = 1; i <= n; i++) {
        // Find colors used by neighbors
        set<int> used;
        for (int neighbor : adj[i]) {
            used.insert(ans[neighbor]);
        }
        
        // Find smallest unused color
        int color = 1;
        while (used.count(color)) color++;
        ans[i] = color;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    ans.resize(n + 1, 0);  // Initialize with 0
    solve(n, v);
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";