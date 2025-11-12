#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct Cow {
    int f, s;
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, M;
    cin >> N >> M;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++){
        cin >> cows[i].f >> cows[i].s;
    }
 
    vector<int> cerealOwner(M+1, -1);
 
    vector<int> visited(M+1, 0);
    int curVisit = 0;
    function<bool(int)> dfs = [&](int i) -> bool {
        int opts[2] = {cows[i].f, cows[i].s};
        for (int k = 0; k < 2; k++){
            int c = opts[k];
            if (visited[c] != curVisit) {
                visited[c] = curVisit;
                if (cerealOwner[c] == -1 || dfs(cerealOwner[c])) {
                    cerealOwner[c] = i;
                    return true;
                }
            }
        }
        return false;
    };
 
    int matchCount = 0;
    for (int i = 0; i < N; i++){
        curVisit++;
        if (dfs(i))
            matchCount++;
    }
 
    vector<int> assign(N, -1);
    for (int c = 1; c <= M; c++){
        if (cerealOwner[c] != -1)
            assign[cerealOwner[c]] = c;
    }
 
    vector<int> type(N, -1);
    for (int i = 0; i < N; i++){
        if (assign[i] != -1) {
            if (assign[i] == cows[i].f)
                type[i] = 0;
            else
                type[i] = 1;
        }
    }
 
    vector<vector<int>> adj(N);
    vector<int> indeg(N, 0);
    for (int i = 0; i < N; i++){
        if (assign[i] != -1 && type[i] == 1) {
            int fav = cows[i].f;
            int j = cerealOwner[fav];
            if(j != -1 && j != i) {
                adj[j].push_back(i);
                indeg[i]++;
            }
        }
    }
 
    queue<int> qu;
    vector<int> fedOrder;
    for (int i = 0; i < N; i++){
        if (assign[i] != -1 && indeg[i] == 0)
            qu.push(i);
    }
    while (!qu.empty()){
        int cur = qu.front();
        qu.pop();
        fedOrder.push_back(cur);
        for (int nxt : adj[cur]){
            if (--indeg[nxt] == 0)
                qu.push(nxt);
        }
    }
    vector<bool> inFedOrder(N, false);
    for (int i : fedOrder) inFedOrder[i] = true;
    for (int i = 0; i < N; i++){
        if (assign[i] != -1 && !inFedOrder[i])
            fedOrder.push_back(i);
    }
 
    vector<int> permutation;
    for (int i : fedOrder)
        permutation.push_back(i);
    for (int i = 0; i < N; i++){
        if (assign[i] == -1)
            permutation.push_back(i);
    }
 
    cout << (N - matchCount) << "\n";
    for (int i : permutation)
        cout << (i + 1) << "\n";
}