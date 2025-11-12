// https://atcoder.jp/contests/abc427/tasks/abc427_d
// Reflections:
// 1. DP with caching, recursion
// 2. 2D DP with 2 states: player and remaining moves

#include <bits/stdc++.h>
using namespace std;

int solve(int player, int u, int rem, vector<vector<int>>& g, vector<vector<vector<int>>>& dp, string& s) {
    int &res = dp[player][u][rem];
    if (res != -1) return res;
    if (rem == 0) {
        if (s[u] == 'A') return res = 0;
        else return res = 1;
    }
    if (player == 0) {
        res = 1;
        for (int v : g[u]) {
            if (solve(1, v, rem - 1, g, dp, s) == 0) res = 0;
        }
        return res;
    } else {
        res = 0;
        for (int v : g[u]) {
            if (solve(0, v, rem - 1, g, dp, s) == 1) res = 1;
        }
        return res;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, m, k; string s; cin >> n >> m >> k >> s;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v; --u; --v;
            g[u].push_back(v);
        }
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(2 * k + 1, -1)));
        cout << (solve(0, 0, 2 * k, g, dp, s) == 0 ? "Alice" : "Bob") << '\n';        
    }
}
