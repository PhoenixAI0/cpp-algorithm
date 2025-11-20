#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    queue<pair<int,int>> q;
    q.push({1,1});
    int m=1;
    while (q.size()) {
        auto x = q.front(); q.pop();
        m = max(m,x.second);
        int l = a[x.first].first,r = a[x.first].second;
        if (l) q.push({l, x.second+1});
        if (r) q.push({r, x.second+1});
    }
    cout<<m;
}
