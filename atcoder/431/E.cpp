#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = (int)1e9;
    int T;
    cin >> T;
    while (T--) {
        int H, W;
        cin >> H >> W;
        vector<string> S(H);
        for (int i = 0; i < H; i++) cin >> S[i];

        int trans[3][4] = {
            {0, 1, 2, 3},
            {1, 0, 3, 2},
            {3, 2, 1, 0}
        };
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        vector<vector<array<int,4>>> dist(H, vector<array<int,4>>(W));
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                dist[i][j].fill(INF);

        deque<tuple<int,int,int>> dq;
        dist[0][0][0] = 0;
        dq.push_back({0,0,0});
        int ans = INF;

        while (!dq.empty()) {
            auto [r,c,d] = dq.front();
            dq.pop_front();
            int cur = dist[r][c][d];
            if (cur > dist[r][c][d]) continue;

            int tcur = (S[r][c] == 'A' ? 0 : (S[r][c] == 'B' ? 1 : 2));

            for (int t = 0; t < 3; t++) {
                int nd = trans[t][d];
                int nr = r + dr[nd];
                int nc = c + dc[nd];
                int w = (t == tcur ? 0 : 1);
                int ncost = cur + w;

                if (0 <= nr && nr < H && 0 <= nc && nc < W) {
                    if (ncost < dist[nr][nc][nd]) {
                        dist[nr][nc][nd] = ncost;
                        if (w == 0) dq.push_front({nr,nc,nd});
                        else dq.push_back({nr,nc,nd});
                    }
                } else {
                    if (r == H - 1 && c == W - 1 && nd == 0)
                        ans = min(ans, ncost);
                }
            }
        }

        if (ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}