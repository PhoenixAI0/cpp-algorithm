#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<int> t;
    Fenwick(int n=0): n(n), t(n+1,0) {}
    void add(int i,int v){for(; i<=n; i+=i&-i) t[i]+=v;}
    int sum(int i){int s=0; for(; i>0; i-=i&-i) s+=t[i]; return s;}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, h; 
    cin >> T >> h;
    while (T--) {
        int n, m; 
        cin >> n >> m;
        vector<long long> a(n+1), b(m+1);
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=m;i++) cin >> b[i];

        if (n != m) {cout << -1 << "\n"; continue;}

        unordered_map<long long, deque<int>> poslist;
        poslist.reserve(n*2);
        for (int i=1;i<=n;i++) poslist[a[i]].push_back(i);

        vector<int> pos(n+1, -1);
        bool flag = true;
        for (int i=1;i<=n;i++){
            auto &dq = poslist[b[i]];
            if (dq.empty()) {flag = false; break;}
            pos[i] = dq.front(); dq.pop_front();
        }
        if (!flag) {cout << -1 << "\n"; continue;}

        Fenwick fw(n);
        for (int i=1;i<=n;i++) fw.add(i, 1);

        vector<array<int,3>> ops;
        for (int i=1;i<=n;){
            int j=i;
            while (j+1<=n && pos[j+1]==pos[j]+1) j++;

            int l = fw.sum(pos[i]);
            int r = fw.sum(pos[j]);

            if (!(l==i && r==j)) {
                ops.push_back({l, r, i-1});
            }
            for (int t=i; t<=j; t++) fw.add(pos[t], -1);

            i = j+1;
        }

        cout << ops.size() << "\n";
        for (auto &o : ops) cout << o[0] << " " << o[1] << " " << o[2] << "\n";
    }
}