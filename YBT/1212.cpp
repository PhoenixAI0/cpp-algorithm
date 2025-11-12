#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 20;
int R, C;
char board[MAXN][MAXN];
bool visitedAlpha[26];    
int ans = 0;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void dfs(int r, int c, int step) {
    ans = max(ans, step);

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr<0 || nr>=R || nc<0 || nc>=C) continue;
        
        int idx = board[nr][nc] - 'A';
        if(!visitedAlpha[idx]){
            visitedAlpha[idx] = true;
            dfs(nr, nc, step+1);
            visitedAlpha[idx] = false;  
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
        }
    }
    visitedAlpha[ board[0][0] - 'A' ] = true;
    dfs(0, 0, 1);

    cout << ans << "\n";
}
