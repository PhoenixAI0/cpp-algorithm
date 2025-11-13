#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n; cin >> n; 
    vector<vector<int>> grid(n, vector<int>(n)); 
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0 && !vis[i][0]) {
            q.push({i, 0});
            vis[i][0] = true;
        }
        if (grid[i][n-1] == 0 && !vis[i][n-1]) {
            q.push({i, n-1});
            vis[i][n-1] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 0 && !vis[0][i]) {
            q.push({0, i});
            vis[0][i] = true;
        }
        if (grid[n-1][i] == 0 && !vis[n-1][i]) {
            q.push({n-1, i});
            vis[n-1][i] = true;
        }
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && 
                grid[nx][ny] == 0 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && !vis[i][j]) {
                grid[i][j] = 2;
            }
            cout << grid[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
}
