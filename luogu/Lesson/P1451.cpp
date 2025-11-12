// https://www.luogu.com.cn/problem/P1451
// Reflections:
// 1. BFS over each untouched point
// 2. Combine visited and grid vectors by turning everything we touch into a wall

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

        for (auto direction : directions) {
            int x = curr.first + direction.first; int y = curr.second + direction.second;
            if (x >= n || x < 0 || y >= m || y < 0) continue;
            if (!grid[x][y]) continue;
            grid[x][y] = false; q.push(make_pair(x, y));
        }     
    }
}

int main() {
    int ans = 0;
    cin >> n >> m;
    grid.resize(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = (s[j] == '0' ? false : true);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j]) {ans++; bfs(i, j);}
    cout << ans << '\n';
}
