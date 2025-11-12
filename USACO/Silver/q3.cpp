#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K = 11;
const ll NEG = -1000000000000000000LL;
struct Node { ll dp[K]; };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> par(N+1);
    vector<ll> d(N+1), e(N+1), F(N+1);
    vector<vector<int>> adj(N+1);
    F[1]=0;
    for(int i=2;i<=N;i++){
        cin >> par[i] >> d[i] >> e[i];
        adj[par[i]].push_back(i);
        F[i] = F[par[i]] + e[i];
    }
    vector<int> in(N+1), out(N+1), ord; ord.reserve(N);
    int timer=0;
    function<void(int)> dfs = [&](int u){
        in[u]=timer++;
        ord.push_back(u);
        for(auto v: adj[u]) dfs(v);
        out[u]=timer;
    };
    dfs(1);
    int n = N, size = 1; while(size < n) size *= 2;
    vector<Node> seg(2*size);
    vector<int> lazy(2*size,0);
    for(int i=0;i<n;i++){
        int u = ord[i];
        for(int j=0;j<K;j++) seg[size+i].dp[j] = F[u];
    }
    for(int i=n;i<size;i++) for(int j=0;j<K;j++) seg[size+i].dp[j] = NEG;
    auto mergeN = [&](const Node &a, const Node &b)->Node{
        Node r; for(int i=0;i<K;i++) r.dp[i] = max(a.dp[i], b.dp[i]); return r;
    };
    for(int i=size-1;i>=1;i--) seg[i] = mergeN(seg[2*i], seg[2*i+1]);
    auto apply = [&](int idx, int val){
        ll tmp[K];
        for(int i=K-1;i>=0;i--){
            tmp[i] = (i-val>=0 ? seg[idx].dp[i-val] : NEG);
        }
        for(int i=0;i<K;i++) seg[idx].dp[i] = tmp[i];
        lazy[idx] += val;
    };
    function<void(int)> push = [&](int idx){
        if(lazy[idx]){
            apply(2*idx, lazy[idx]);
            apply(2*idx+1, lazy[idx]);
            lazy[idx] = 0;
        }
    };
    function<void(int,int,int,int,int)> upd = [&](int idx, int l, int r, int ql, int qr){
        if(ql>=r || qr<=l)return;
        if(ql<=l && r<=qr){ apply(idx,1); return; }
        push(idx); int mid=(l+r)/2;
        upd(2*idx,l,mid,ql,qr); upd(2*idx+1,mid,r,ql,qr);
        seg[idx] = mergeN(seg[2*idx], seg[2*idx+1]);
    };
    int M; cin >> M;
    vector<array<ll,3>> Q(M);
    for(int i=0;i<M;i++){
        ll s, c; cin >> s >> c;
        Q[i] = {s, c, i};
    }
    sort(Q.begin(), Q.end(), [](auto &a, auto &b){ return a[0]>b[0]; });
    vector<tuple<ll,int,int>> edges;
    for(int i=2;i<=N;i++) edges.push_back({d[i], par[i], i});
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return get<0>(a) > get<0>(b); });
    int j=0;
    vector<ll> ans(M);
    for(auto &q : Q){
        ll s = q[0], c = q[1], qi = q[2];
        while(j < edges.size() && get<0>(edges[j]) > s){
            int node = get<2>(edges[j]);
            upd(1,0,size,in[node],out[node]);
            j++;
        }
        ans[qi] = seg[1].dp[c];
    }
    for(auto a : ans) cout << a << "\n";
}