#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> fenw;
    Fenwick(int n) : n(n), fenw(n+1,0) {}
    
    void update(int i, int delta) {
        for(; i<=n; i+=(i & -i)) {
            fenw[i] += delta;
        }
    }
    
    int query(int i) const {
        int s = 0;
        for(; i>0; i-=(i & -i)) {
            s += fenw[i];
        }
        return s;
    }
    
    int rangeQuery(int l, int r) const {
        if(l>r) return 0;
        return query(r) - query(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> E(N+1);
    for(int i=1; i<=N; i++){
        cin >> E[i];
    }
    
    vector<int> prefG(N+1,0), prefH(N+1,0);
    int totalG = 0, totalH = 0;
    for(int i=1; i<=N; i++){
        prefG[i] = prefG[i-1] + (S[i-1]=='G');
        prefH[i] = prefH[i-1] + (S[i-1]=='H');
    }
    totalG = prefG[N];
    totalH = prefH[N];
    
    auto coversAllG = vector<bool>(N+1,false);
    auto coversAllH = vector<bool>(N+1,false);
    for(int i=1; i<=N; i++){
        int gInRange = prefG[E[i]] - prefG[i-1];
        if(gInRange == totalG) coversAllG[i] = true;
        int hInRange = prefH[E[i]] - prefH[i-1];
        if(hInRange == totalH) coversAllH[i] = true;
    }
    
    vector<int> GA, GB, HA, HB;
    GA.reserve(N);  GB.reserve(N);
    HA.reserve(N);  HB.reserve(N);
    
    for(int i=1; i<=N; i++){
        if(S[i-1] == 'G') {
            if(coversAllG[i]) GA.push_back(i);
            else              GB.push_back(i);
        } else {
            if(coversAllH[i]) HA.push_back(i);
            else              HB.push_back(i);
        }
    }
    
    long long countAC = 1LL * GA.size() * HA.size();
    
    long long countAD = 0;
    {
        vector<pair<int,int>> hvec;
        hvec.reserve(HB.size());
        for(int j: HB) {
            hvec.push_back({j, E[j]});
        }
        sort(hvec.begin(), hvec.end(), 
             [](auto &a, auto &b){return a.first < b.first;});
        
        sort(GA.begin(), GA.end());
        
        Fenwick fenw(N); 
        int idx = 0;
        for(int i: GA) {
            while(idx < (int)hvec.size() && hvec[idx].first <= i) {
                fenw.update(hvec[idx].second, +1);
                idx++;
            }
            countAD += fenw.rangeQuery(i, N);
        }
    }
    
    long long countBC = 0;
    {
        vector<pair<int,int>> gvec;
        gvec.reserve(GB.size());
        for(int i: GB) {
            gvec.push_back({i, E[i]});
        }
        sort(gvec.begin(), gvec.end(),
             [](auto &a, auto &b){return a.first < b.first;});
        
        sort(HA.begin(), HA.end());
        
        Fenwick fenw(N);
        int idx = 0;
        for(int j: HA) {
            while(idx < (int)gvec.size() && gvec[idx].first <= j) {
                fenw.update(gvec[idx].second, +1);
                idx++;
            }
            countBC += fenw.rangeQuery(j, N);
        }
    }
    
    long long ans = countAC + countAD + countBC;
    cout << ans << "\n";
}