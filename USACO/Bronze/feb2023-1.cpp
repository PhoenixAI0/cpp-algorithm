#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, T;
    cin >> N >> T;
    
    vector<pair<ll, ll>> deliveries(N);
    for(int i = 0; i < N; ++i){
        cin >> deliveries[i].first >> deliveries[i].second;
    }
    
    ll current_day = 0;
    ll hay = 0;
    ll eaten = 0;
    
    for(auto &[d, b] : deliveries){
        ll gap = d - current_day - 1;
        
        if(gap > 0){
            ll eatGap = min(hay, gap);
            eaten += eatGap;
            hay -= eatGap;
        }
        
        current_day = d;
        
        hay += b;
        
        if(hay > 0){
            eaten += 1;
            hay -= 1;
        }
    }
    
    if(current_day < T){
        ll remaining_days = T - current_day;
        ll eatRemaining = min(hay, remaining_days);
        eaten += eatRemaining;
    }
    
    cout << eaten << "\n";
}