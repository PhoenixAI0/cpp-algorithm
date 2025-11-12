#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;  

    while (k--) {
        int n;
        cin >> n;  

        vector<vector<char>> maze(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }

        int ha, la, hb, lb;
        cin >> ha >> la >> hb >> lb;

        if (ha < 0 || ha >= n || la < 0 || la >= n ||
            hb < 0 || hb >= n || lb < 0 || lb >= n) {
            cout << "NO\n";
            continue;
        }
        if (maze[ha][la] == '#' || maze[hb][lb] == '#') {
            cout << "NO\n";
            continue;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        
        q.push({ha, la});
        visited[ha][la] = true;

        bool canReach = false;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            
            if (r == hb && c == lb) {
                canReach = true;
                break;
            }

            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (!visited[nr][nc] && maze[nr][nc] == '.') {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        if (canReach) cout << "YES\n";
        else cout << "NO\n";
    }
}
