#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    a1--; a2--; b1--; b2--;
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }
    
    reverse(pos.begin() + a1, pos.begin() + a2 + 1);
    reverse(pos.begin() + b1, pos.begin() + b2 + 1);
    
    vector<bool> visited(n);
    vector<int> result(n);
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        vector<int> cycle;
        int curr = i;
        while (!visited[curr]) {
            visited[curr] = true;
            cycle.push_back(curr);
            curr = pos[curr];
        }
        
        int cycle_len = cycle.size();
        int offset = k % cycle_len;
        
        for (int j = 0; j < cycle.size(); j++) {
            result[cycle[j]] = cycle[(j + offset) % cycle_len];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] + 1 << "\n";
    }
}
