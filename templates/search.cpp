#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> grid;
static const vector<pair<int, int>> directions {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}
};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    grid[i][j] = false;
    q.push(make_pair(i, j));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.first == n - 1 && curr.second == m - 1) {
            // END CONDITION
        }

        for (auto direction : directions) {
            int x = curr.first + direction.first; int y = curr.second + direction.second;
            if (x >= n || x < 0 || y >= m || y < 0) continue;
            if (!grid[x][y]) continue;
            grid[x][y] = false; q.push(make_pair(x, y));
        }
    }
}

void dfs_nonrecursive(int i, int j) {
    stack<pair<int, int>> s;
    grid[i][j] = false;
    s.push(make_pair(i, j));

    while (!s.empty()) {
        auto curr = s.top();
        s.pop();

        if (curr.first == n - 1 && curr.second == m - 1) {
            // END CONDITION
        }

        for (auto direction : directions) {
            int x = curr.first + direction.first; int y = curr.second + direction.second;
            if (x >= n || x < 0 || y >= m || y < 0) continue;
            if (!grid[x][y]) continue;
            grid[x][y] = false; s.push(make_pair(x, y));
        }
    }
}

void dfs_recursion(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0 || !grid[i][j]) return;
    grid[i][j] = false;
    if (i == n - 1 && j == m - 1) {
        // END CONDITION
    }
    for (auto direction : directions) search(x + direction.first, y + direction.second);
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = (s[j] == '0' ? false : true);
    }
}
