#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<bool>> visited;
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
    return grid[x][y] + best;
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << dfs(0, 0) << "\n";
}