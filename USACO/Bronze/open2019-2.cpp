#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> directions(n-1);
    for (int i = 0; i < n - 1; i++) {
        cin >> directions[i].first >> directions[i].second;
    }
    vector<vector<int>> adj(n + 1);
    for (auto [a, b] : directions) {
        adj[a].push_back(b);  // a -> b means waste flows from a to b
    }
    
    int ans = -1;
    for (int sink = 1; sink <= n; sink++) {
        // Check if this is a potential sink (no outgoing edges)
        bool has_outgoing = false;
        for (auto [a, b] : directions) {
            if (a == sink) {
                has_outgoing = true;
                break;
            }
        }
        if (has_outgoing) continue;
        
        // For each node, check if it can reach sink
        bool all_can_reach = true;
        for (int start = 1; start <= n; start++) {
            if (start == sink) continue;
            
            // Try to reach sink from this node
            vector<bool> visited(n + 1);
            function<bool(int)> dfs = [&](int v) {
                if (v == sink) return true;
                visited[v] = true;
                for (int u : adj[v]) {
                    if (!visited[u] && dfs(u)) return true;
                }
                return false;
            };
            
            if (!dfs(start)) {
                all_can_reach = false;
                break;
            }
        }
        
        if (all_can_reach) {
            ans = sink;
            break;
        }
    }
    
    cout << ans << "\n";
}