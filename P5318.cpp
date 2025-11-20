#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005],d,b;
bool v[100005],w[100005];
void f(int x){
    v[x]=1;d.push_back(x);
    for(int y:g[x])if(!v[y])f(y);
}
int main(){
    int n,m,x,y;cin>>n>>m;
    while(m--){cin>>x>>y;g[x].push_back(y);}
    for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
    f(1);
    queue<int>q;q.push(1);w[1]=1;
    while(q.size()){
        x=q.front();q.pop();b.push_back(x);
        for(int y:g[x])if(!w[y])w[y]=1,q.push(y);
    }
    for(auto& a : d) cout << a << " ";
    cout<<'\n';
    for(auto& a : b) cout << a << " ";
}
