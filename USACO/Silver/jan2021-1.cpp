#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, K;
    cin >> N >> K;
    
    vector<int> pos(N+1);
    vector<vector<int>> visited(N+1);
    
    for(int i = 1; i <= N; i++){
        pos[i] = i;
        visited[i].push_back(i);
    }
    
    vector<pair<int,int>> swaps(K);
    for (int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        swaps[i] = {a, b};
    }
    
    for (int i = 0; i < K; i++){
        int a = swaps[i].first, b = swaps[i].second;
        int cowA = pos[a], cowB = pos[b];
        swap(pos[a], pos[b]);
        visited[cowA].push_back(b);
        visited[cowB].push_back(a);
    }
    
    vector<int> f(N+1);
    for (int p = 1; p <= N; p++){
        int cow = pos[p];
        f[cow] = p;
    }
 
    vector<int> ans(N+1, 0);
    vector<bool> done(N+1, false);
    vector<int> mark(N+1, 0);
    int curMark = 0;
 
    for (int i = 1; i <= N; i++){
        if(done[i]) continue;
        vector<int> cycle;
        int cur = i;
        while(!done[cur]){
            done[cur] = true;
            cycle.push_back(cur);
            cur = f[cur];
        }
 
        curMark++; 
        int cnt = 0;
        for (int node : cycle){
            for (int posVisited : visited[node]){
                if(mark[posVisited] != curMark){
                    mark[posVisited] = curMark;
                    cnt++;
                }
            }
        }
        for (int node : cycle){
            ans[node] = cnt;
        }
    }
 
    for (int i = 1; i <= N; i++){
        cout << ans[i] << "\n";
    }
}