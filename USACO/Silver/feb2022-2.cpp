#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct PairHash {
    size_t operator()(const pair<ll,ll> &p) const {
        auto h1 = std::hash<ll>()(p.first);
        auto h2 = std::hash<ll>()(p.second);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N; 
    cin >> N;
    ll xg, yg;
    cin >> xg >> yg;
    vector<pair<ll,ll>> instr(N);
    for (int i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        instr[i] = {a, b};
    }
 
    int n1 = N / 2;
    int n2 = N - n1;
    vector<pair<ll,ll>> group1(instr.begin(), instr.begin()+n1);
    vector<pair<ll,ll>> group2(instr.begin()+n1, instr.end());
 
    vector<unordered_map<pair<ll,ll>, ll, PairHash>> dp1(n1+1);
    dp1[0][{0,0}] = 1;
    for (int i = 0; i < n1; i++){
        auto [dx, dy] = group1[i];
        for (int cnt = i; cnt >= 0; cnt--){
            for (auto &entry : dp1[cnt]) {
                auto curSum = entry.first;
                ll ways = entry.second;
                pair<ll,ll> newSum = {curSum.first + dx, curSum.second + dy};
                dp1[cnt+1][newSum] += ways;
            }
        }
    }
 
    vector<unordered_map<pair<ll,ll>, ll, PairHash>> dp2(n2+1);
    dp2[0][{0,0}] = 1;
    for (int i = 0; i < n2; i++){
        auto [dx, dy] = group2[i];
        for (int cnt = i; cnt >= 0; cnt--){
            for (auto &entry : dp2[cnt]) {
                auto curSum = entry.first;
                ll ways = entry.second;
                pair<ll,ll> newSum = {curSum.first + dx, curSum.second + dy};
                dp2[cnt+1][newSum] += ways;
            }
        }
    }
 
    vector<ll> ans(N+1, 0);
    for (int k = 1; k <= N; k++){
        ll waysK = 0;
        int lowc = max(0, k - n2);
        int highc = min(k, n1);
        for (int c = lowc; c <= highc; c++){
            int d = k - c;
            for (auto &entry : dp1[c]){
                auto sum1 = entry.first;
                ll ways1 = entry.second;
                pair<ll,ll> needed = {xg - sum1.first, yg - sum1.second};
                if(dp2[d].find(needed) != dp2[d].end()){
                    waysK += ways1 * dp2[d][needed];
                }
            }
        }
        ans[k] = waysK;
    }
 
    for (int k = 1; k <= N; k++){
        cout << ans[k] << "\n";
    }
}