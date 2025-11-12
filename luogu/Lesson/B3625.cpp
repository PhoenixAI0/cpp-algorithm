#include <bits/stdc++.h>
using namespace std;
int n, m; 
vector<vector<bool>> grid;
vector<pair<int, int>> directions = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}
};

void search(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0 || !grid[x][y]) return;
    grid[x][y] = false;
    if (x == n - 1 && y == m - 1) {
        cout << "Yes" << "\n";
        exit(0);
    }
    for (auto direction : directions) search(x + direction.first, y + direction.second);
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') grid[i][j] = true;
        }
    }
    search(0, 0);
    cout << "No" << "\n";
}
