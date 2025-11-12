#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
vector<pair<int, int>> moves = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, 
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};
int numAnswers;

void search(vector<vector<bool>>& grid, int visitedCount, pair<int, int> location) {
    if (visitedCount == n * m) {
        numAnswers++;
        return;
    }

    for (auto& move : moves) {
        int newX = location.first + move.first;
        int newY = location.second + move.second;

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !grid[newX][newY]) {
            grid[newX][newY] = true;
            search(grid, visitedCount + 1, {newX, newY});
            grid[newX][newY] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> x >> y;

        vector<vector<bool>> grid(n, vector<bool>(m, false));
        grid[x][y] = true;
        numAnswers = 0;

        search(grid, 1, {x, y});

        cout << numAnswers << '\n';
    }
}