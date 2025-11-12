#include <bits/stdc++.h>
using namespace std;
static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y,
         const vector<vector<bool>> &grid,
         vector<vector<pair<int,int>>> &all,
         vector<pair<int,int>> &current,
         vector<vector<bool>> &visited) {
    int n = grid.size(), m = grid[0].size();

    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] || visited[x][y]) return;

    current.push_back({x, y});
    visited[x][y] = true;

    if (x == n - 1 && y == m - 1) all.push_back(current);
    else for (auto [dx, dy] : DIRECTIONS) dfs(x + dx, y + dy, grid, all, current, visited);

    visited[x][y] = false;
    current.pop_back();
}

vector<vector<pair<int,int>>> floodfill(const vector<vector<bool>> &grid) {
    vector<vector<pair<int,int>>> all;
    vector<pair<int,int>> current;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    dfs(0, 0, grid, all, current, visited);
    return all;
}

int main() {
    int n; cin >> n;
    vector<vector<bool>> grid;
    grid.resize(3, vector<bool>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c; grid[i][j] = (c == '#') ? true : false;
        }
    }
    auto paths = floodfill(grid);
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        cout << paths[x][y] << "\n";
    }
}
