#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
vector<ll> A;
vector<vector<int>> adj;
ll ans = 0;
vector<bool> used;

void backtrack(int k, ll sum) {
    ans = max(ans, sum);
    if (k == 0) return;
    
    for (int u = 1; u <= N; u++) {
        if (used[u]) continue;
        
        ll path_sum = A[u];
        vector<int> path = {u};
        used[u] = true;
        
        function<void(int, int)> extend = [&](int node, int parent) {
            ans = max(ans, sum + path_sum);
            
            for (int child : adj[node]) {
                if (child != parent && !used[child]) {
                    used[child] = true;
                    path.push_back(child);
                    path_sum += A[child];
                    
                    backtrack(k - 1, sum + path_sum);
                    extend(child, node);
                    
                    path_sum -= A[child];
                    path.pop_back();
                    used[child] = false;
                }
            }
        };
        
        backtrack(k - 1, sum + path_sum);
        extend(u, -1);
        
        used[u] = false;
    }
}

int main() {
    cin >> N >> K;
    A.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    adj.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    used.resize(N + 1, false);
    backtrack(K, 0);
    
    cout << ans << '\n';
}
