#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    
    int N; cin >> N;
    
    vector<int> degree(N + 1, 0);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    cout << *max_element(degree.begin(), degree.end()) + 1;
}