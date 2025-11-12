#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;

struct S {
    int d[3][3];
    int len;
};

const int INF = 1'000'000'000;

S e() {
    S x;
    x.len = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            x.d[i][j] = (i == j ? 0 : INF);
    return x;
}

S op(const S& a, const S& b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    S c;
    c.len = a.len + b.len;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int best = INF;
            for (int k = 0; k < 3; ++k) {
                if (a.d[i][k] >= INF || b.d[k][j] >= INF) continue;
                best = min(best, a.d[i][k] + 1 + b.d[k][j]);
            }
            c.d[i][j] = best;
        }
    }
    return c;
}

int N, Q;
vector<string> grid;

S make_leaf(int c) {
    bool open[3];
    for (int r = 0; r < 3; ++r) open[r] = (grid[r][c] == '.');

    S x;
    x.len = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            x.d[i][j] = INF;

    for (int i = 0; i < 3; ++i) {
        if (!open[i]) continue;
        for (int j = 0; j < 3; ++j) {
            if (!open[j]) continue;
            if (i == j) x.d[i][j] = 0;
            else if (abs(i - j) == 1) x.d[i][j] = 1;
            else if (open[1]) x.d[i][j] = 2;
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    grid.resize(3);
    for (int r = 0; r < 3; ++r) cin >> grid[r];

    vector<S> init(N);
    for (int c = 0; c < N; ++c) init[c] = make_leaf(c);

    atcoder::segtree<S, op, e> seg(init);

    int Q; cin >> Q;
    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        grid[r][c] = (grid[r][c] == '.') ? '#' : '.';
        seg.set(c, make_leaf(c));

        S all = seg.all_prod();
        int ans = all.d[0][2];
        cout << (ans >= INF ? -1 : ans) << '\n';
    }
}