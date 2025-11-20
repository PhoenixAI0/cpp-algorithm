#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
vector<int> rg[100005];
int a[100005], in[100005], o[100005];

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i;
    while (m--) {
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
        in[x]++;
    }
    iota(o + 1, o + n + 1, 1);
    sort(o + 1, o + n + 1, greater<int>());
    for (int idx = 1; idx <= n; idx++) {
        int i = o[idx];
        for (int v : g[i]) if (a[i] < a[v]) a[i] = a[v];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
