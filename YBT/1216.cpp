#include <bits/stdc++.h>
using namespace std;

static const int MAXW = 20;
static const int MAXH = 20;

int W, H;
vector<string> grid;            
bool visited[MAXH][MAXW];       

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int r, int c) {
    visited[r][c] = true;
    int count = 1; 

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr >= 0 && nr < H && nc >= 0 && nc < W) {
            
            if(!visited[nr][nc] && (grid[nr][nc] == '.' || grid[nr][nc] == '@')) {
                count += dfs(nr, nc);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> W >> H;
        if(!cin || (W == 0 && H == 0)) {
            break;
        }
        
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        grid.resize(H);
        int startR = -1, startC = -1;

        
        for(int i = 0; i < H; i++) {
            getline(cin, grid[i]);  
            
            for(int j = 0; j < W; j++) {
                if(grid[i][j] == '@') {
                    startR = i;
                    startC = j;
                }
            }
        }
        
        memset(visited, false, sizeof(visited));

        int result = dfs(startR, startC);
        cout << result << "\n";
    }
}
