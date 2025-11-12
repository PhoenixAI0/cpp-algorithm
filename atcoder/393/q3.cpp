#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> unique_edges;
    int remove_count = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        if (u == v) { 
            remove_count++;
            continue;
        }

        if (u > v) swap(u, v); 

        if (unique_edges.find({u, v}) != unique_edges.end()) {
            remove_count++; 
        } else {
            unique_edges.insert({u, v});
        }
    }

    cout << remove_count << "\n";
}