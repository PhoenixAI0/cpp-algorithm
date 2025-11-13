#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> cache;
int n, m;

int dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) return INT_MIN;
    if (x == n - 1 && y == m - 1) return grid[x][y];
    visited[x][y] = true;
    int up = dfs(x - 1, y);
    int right = dfs(x, y + 1);
    int down = dfs(x + 1, y);
    visited[x][y] = false;
    int best = max({up, right, down});
    if (best == INT_MIN) return INT_MIN;
    int result = grid[x][y] + best;
    if (cache[x][y] == INT_MIN || result > cache[x][y]) cache[x][y] = result;
    return result;
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    cache.resize(n, vector<int>(m, INT_MIN));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    cout << dfs(0, 0) << "\n";
}
