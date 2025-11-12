#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N; 
    cin >> N;
    vector<vector<int>> pref(N, vector<int>(N));
    vector<vector<int>> rankPos(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int x;
            cin >> x;
            x--;
            pref[i][j] = x;
        }
        for (int j = 0; j < N; j++){
            int gift = pref[i][j];
            rankPos[i][gift] = j;
        }
    }
    vector<vector<int>> g(N);
    for (int i = 0; i < N; i++){
        int thresh = rankPos[i][i];
        for (int pos = 0; pos < thresh; pos++){
            int cand = pref[i][pos];
            g[i].push_back(cand);
        }
    }

    vector<int> disc(N, -1), low(N, 0), compIndex(N, -1);
    vector<bool> inStack(N, false);
    vector<int> st;
    int timeCounter = 0, compCount = 0;
    vector<vector<int>> comps;
 
    function<void(int)> tarjan = [&](int v) -> void {
        disc[v] = low[v] = timeCounter++;
        st.push_back(v);
        inStack[v] = true;
        for (int w : g[v]){
            if(disc[w] == -1){
                tarjan(w);
                low[v] = min(low[v], low[w]);
            } else if(inStack[w]){
                low[v] = min(low[v], disc[w]);
            }
        }
        if(low[v] == disc[v]){
            vector<int> compNodes;
            while(true){
                int w = st.back();
                st.pop_back();
                inStack[w] = false;
                compIndex[w] = compCount;
                compNodes.push_back(w);
                if(w == v) break;
            }
            comps.push_back(compNodes);
            compCount++;
        }
    };
    for (int i = 0; i < N; i++){
        if(disc[i] == -1)
            tarjan(i);
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++){
        int cid = compIndex[i];
        if(comps[cid].size() == 1){
            ans[i] = i;
        } else {
            int bestCandidate = i;
            int bestPos = INT_MAX;
            for (int j : comps[cid]){
                if(j == i) continue;
                if(rankPos[i][j] < rankPos[i][i] && rankPos[i][j] < bestPos){
                    bestPos = rankPos[i][j];
                    bestCandidate = j;
                }
            }
            ans[i] = bestCandidate;
        }
    }

    for (int i = 0; i < N; i++){
        cout << ans[i] + 1 << "\n";
    }
}