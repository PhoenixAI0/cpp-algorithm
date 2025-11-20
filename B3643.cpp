#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n);

    while (m--) {
        cin >> u >> v;
        u--; v--;
        a[u][v] = a[v][u] = 1;
        b[u].push_back(v + 1);
        b[v].push_back(u + 1);
    }

    for (auto& x : a) {
        for (int j = 0; j < n; j++) cout << x[j] << ' ';
        cout << '\n';
    }

    for (auto& x : b) {
        sort(x.begin(), x.end());
        cout << x.size();
        for (int j = 0; j < x.size(); j++) cout << ' ' << x[j];
        cout << '\n';
    }
}
