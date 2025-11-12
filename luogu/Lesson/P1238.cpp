// https://www.luogu.com.cn/problem/P1238
// Reflections:
// 1. Simple DFS, BFS also works
// 2. Remember direction order

#include <bits/stdc++.h>
using namespace std;
int m, n;
static const vector<pair<int, int>> directions = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};
vector<vector<bool>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> path;
bool ans = false;

void dfs(int x, int y, int endx, int endy) {
    if (x == endx && y == endy) {
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << (path[i].first + 1) << "," << path[i].second + 1 << ")" << (i == path.size() - 1 ? "\n" : "->");
            ans = true;
        }
        return;
    }
    for (auto direction : directions) {
        int nx = x + direction.first, ny = y + direction.second;
        if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
        if (!grid[nx][ny] || visited[nx][ny]) continue;
        path.push_back(make_pair(nx, ny));
        visited[nx][ny] = true;
        dfs(nx, ny, endx, endy);
        visited[nx][ny] = false;
        path.pop_back();
    }
}

int main() {
    cin >> m >> n;
    grid.resize(m, vector<bool>(n));
    visited.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {int x; cin >> x; grid[i][j] = x;}
    }
    int startx, starty, endx, endy; cin >> startx >> starty >> endx >> endy;
    startx--; starty--; endx--; endy--;
    path.push_back(make_pair(startx, starty));
    visited[startx][starty] = true;
    dfs(startx, starty, endx, endy);
    if (!ans) cout << -1 << "\n";
}
