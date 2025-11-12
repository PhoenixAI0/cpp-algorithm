// https://atcoder.jp/contests/abc427/tasks/abc427_c
// Reflections:
// 1. Brute-force bitmask to explore all vertexes
// 2. O(M * 2^N) time, but acceptable for N <= 10
// 3. Remember to convert to 0-indexed
// 4. auto [u, v] : edges when iterating

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> edges(M);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        --u; --v; 
        edges[i] = {u, v};
    }

    ll best = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        ll cross = 0;
        for (auto [u, v] : edges) {
            if (((mask >> u) & 1) != ((mask >> v) & 1)) ++cross;
        }
        best = max(best, cross);
    }

    cout << (M - best) << "\n";
}