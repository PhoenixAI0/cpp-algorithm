#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
char flipChar(char c) {
    return (c=='R' ? 'L' : 'R');
}
 
string complementStr(const string &s) {
    string ret = s;
    for (char &c : ret)
        c = flipChar(c);
    return ret;
}
 
bool isRowConsistent(const string &base, const string &r) {
    bool same = true, opp = true;
    int n = base.size();
    for (int j = 0; j < n; j++){
        if(r[j] != base[j])
            same = false;
        if(r[j] != flipChar(base[j]))
            opp = false;
        if(!same && !opp)
            return false;
    }
    return true;
}
 
bool canUniformize(const vector<string> &grid, const string &base) {
    int N = grid.size();
    for (int i = 1; i < N; i++){
        if(!isRowConsistent(base, grid[i]))
            return false;
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
 
    int N; 
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++){
        cin >> grid[i];
    }
 
    bool alreadyUniform = true;
    for (int i = 1; i < N; i++){
        if(!isRowConsistent(grid[0], grid[i])){
            alreadyUniform = false;
            break;
        }
    }
    if(alreadyUniform){
        cout << -1 << "\n";
        return 0;
    }
 
    int candidateRowNon0 = -1, candidateColNon0 = -1;
    int inconsistentRows = 0;
    for (int i = 1; i < N; i++){
        int cntSame = 0;
        for (int j = 0; j < N; j++){
            if(grid[i][j] == grid[0][j])
                cntSame++;
        }
        if(cntSame == N || cntSame == 0)
            continue;
 
        inconsistentRows++;
        if(cntSame == 1){
            int col;
            for (int j = 0; j < N; j++){
                if(grid[i][j] == grid[0][j]){
                    col = j;
                    break;
                }
            }
            if(candidateRowNon0 == -1){
                candidateRowNon0 = i;
                candidateColNon0 = col;
            } else {
                candidateRowNon0 = -2;
            }
        } else if(cntSame == N-1){
            int col;
            for (int j = 0; j < N; j++){
                if(grid[i][j] != grid[0][j]){
                    col = j;
                    break;
                }
            }
            if(candidateRowNon0 == -1){
                candidateRowNon0 = i;
                candidateColNon0 = col;
            } else {
                candidateRowNon0 = -2;
            }
        } else { 
            candidateRowNon0 = -2;
        }
    }
    bool validNon0Candidate = (inconsistentRows == 1 && candidateRowNon0 >= 0);
 
    int candidateRow0 = -1, candidateCol0 = -1;
    for (int j = 0; j < N; j++){
        string newRow0 = grid[0];
        newRow0[j] = flipChar(newRow0[j]);
        if(canUniformize(grid, newRow0)){
            candidateRow0 = 0;
            candidateCol0 = j;
            break;
        }
    }
 
    int finalRow, finalCol;
    if(candidateRow0 != -1){
        finalRow = candidateRow0;
        finalCol = candidateCol0;
    } else if(validNon0Candidate){
        finalRow = candidateRowNon0;
        finalCol = candidateColNon0;
    } else {
        cout << -1 << "\n";
        return 0;
    }
 
    cout << (finalRow + 1) << " " << (finalCol + 1) << "\n";
}