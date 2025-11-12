#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

int greedyAlgo(const vector<int>& a){
    int len=a.size();
    int r=len/2;
    vector<int> h(r+1,0);
    unordered_map<int, vector<int>> pos;
    for(int i=0;i<2*r;i++) pos[a[i]].push_back(i);
    for(auto &kv:pos){
        auto b=kv.second;
        int k=b.size();
        for(int x=0;x<k;x++){
            for(int y=x+1;y<k && b[y]-b[x]<=r;y++){
                int d=b[y]-b[x];
                if(b[x]<d && d<=r) h[d]=1;
            }
        }
    }
    vector<int> f(r+2,0), best(r+3,0);
    for(int i=r;i>=1;i--){
        int nxt = 2*i;
        int nxtBest = (nxt<=r)?best[nxt]:0;
        f[i]=h[i]+nxtBest;
        best[i]=max(f[i], best[i+1]);
    }
    return best[1];
}

int brute(const vector<int>& a){
    int n=a.size();
    int r=n/2; 
    vector<int> h(r+1,0);
    for(int d=1; d<=r; ++d){
        bool ok=false;
        for(int i=0;i<d;i++) if(a[i]==a[d+i]) {ok=true;break;} 
        h[d]=ok; 
    }
    int best=0;
    function<void(int,int)> dfs=[&](int s_prev, int sum){
        best=max(best,sum);
        for(int s=(s_prev==0?1:2*s_prev); s<=r; ++s){
            dfs(s, sum + h[s]);
        }
    };
    dfs(0, 0);
    return best;
}

int main(){
    std::mt19937 rng(123);
    for(int n=1;n<=12;n++){
        for(int t=0;t<400;t++){
            vector<int> a(n);
            for(int i=0;i<n;i++) a[i]=rng()%4;
            int g=greedyAlgo(a);
            int b=brute(a);
            if(g!=b){
                cerr<<"Mismatch n="<<n<<" greedy="<<g<<" brute="<<b<<"\n";
                cerr<<"a:"; for(int x:a) cerr<<x<<" "; cerr<<"\n";
                return 0;
            }
        }
    }
    cerr<<"All ok\n";
}
