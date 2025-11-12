// https://www.luogu.com.cn/problem/B3624
// Reflections:
// 1. When getting w input, i starts at 1 not 0 due to padding

#include <bits/stdc++.h>
using namespace std;
int n, l, r; vector<int> w;
int ans = 0;

void dfs(int idx = 0, int weight = 0) {
    if (weight > r) return;
    if (idx > n) return;
    if (weight >= l) ans++;
    for (int i = idx + 1; i <= n; i++) dfs(i, weight + w[i]);
}

int main() {
    cin >> n >> l >> r;
    w.resize(n+1); w.push_back(0); for (int i = 1; i <= n; i++) cin >> w[i];
    dfs();
    cout << ans;
}
