#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> dfs_result;
    stack<int> st;
    st.push(1);
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (!visited[u]) {
            visited[u] = true;
            dfs_result.push_back(u);
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                st.push(*it);
            }
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    vector<int> bfs_result;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfs_result.push_back(u);
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    for (size_t i = 0; i < dfs_result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << dfs_result[i];
    }
    cout << '\n';
    
    for (size_t i = 0; i < bfs_result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << bfs_result[i];
    }
    cout << '\n';
}