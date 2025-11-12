#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> moves = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1}
};


int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    x--; y--;
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    
    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for (auto& move : moves) {
            int newX = currX + move.first;
            int newY = currY + move.second;
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[currX][currY] + 1;
                q.push({newX, newY});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << "\n";
    }
}
