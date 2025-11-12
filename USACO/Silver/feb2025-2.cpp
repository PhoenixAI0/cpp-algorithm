#include <bits/stdc++.h>
using namespace std;

static const int MX=1000000,LG=20;

int N;
int p[MX+1],dep[MX+1],P[MX+1][LG];
vector<pair<int,int>> adj[MX+1]; 
vector<int> leaves;
int pos[MX+1],lcpVal[MX],Lnext[MX],Lprev[MX];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>p[i];
        adj[p[i]].push_back({i,i});
    }
    for(int i=0;i<=N;i++){
        sort(adj[i].begin(),adj[i].end(),[&](auto &A,auto &B){
            return A.second < B.second;
        });
    }
    {
        for(int i=1;i<=N;i++) dep[i]=dep[p[i]]+1;
        for(int i=0;i<=N;i++) P[i][0]=p[i];
        for(int k=1;k<LG;k++){
            for(int i=0;i<=N;i++){
                P[i][k]=P[P[i][k-1]][k-1];
            }
        }
    }
    auto lca=[&](int a,int b){
        if(dep[a]<dep[b]) swap(a,b);
        int d=dep[a]-dep[b];
        for(int k=0;k<LG;k++) if(d&(1<<k)) a=P[a][k];
        if(a==b) return a;
        for(int k=LG-1;k>=0;k--) if(P[a][k]!=P[b][k]){a=P[a][k];b=P[b][k];}
        return p[a];
    };
    for(int i=0;i<=N;i++){
        if(adj[i].empty()) leaves.push_back(i);
    }
    int M=leaves.size();
    vector<int> lexLeaves; 
    lexLeaves.reserve(M);
    {
        vector<int> stk; 
        stk.push_back(0);
        vector<int> idx(adj[0].size(),0); 
        function<void(int)> dfsOrder=[&](int u){
            if(adj[u].empty()) lexLeaves.push_back(u);
            for(auto &ed:adj[u]){
                dfsOrder(ed.first);
            }
        };
        dfsOrder(0);
    }
    for(int i=0;i<M;i++){
        pos[lexLeaves[i]]=i;
    }
    for(int i=0;i+1<M;i++){
        int c = lca(lexLeaves[i],lexLeaves[i+1]);
        lcpVal[i]=dep[c];
    }
    for(int i=0;i<M;i++){
        Lnext[i]=(i==M-1?-1:i+1);
        Lprev[i]=(i==0?-1:i-1);
    }
    vector<int> quiz(M),ans(M);
    for(int i=0;i<M;i++) cin>>quiz[i];
    int rem=M;
    for(int i=0;i<M;i++){
        int w=quiz[i],idx=pos[w];
        if(rem==1){
            ans[i]=0;
        } else {
            int l=Lprev[idx],r=Lnext[idx],mx=0;
            if(l!=-1) mx=max(mx,lcpVal[l]);
            if(r!=-1) mx=max(mx,lcpVal[idx]);
            ans[i]=mx+1;
        }
        rem--;
        int L=Lprev[idx],R=Lnext[idx];
        if(L!=-1) Lnext[L]=R;
        if(R!=-1) Lprev[R]=L;
        if(L!=-1&&R!=-1){
            int c=lca(lexLeaves[L],lexLeaves[R]);
            lcpVal[L]=dep[c];
        }
    }
    for(int i=0;i<M;i++){
        cout<<ans[i]<<"\n";
    }
}