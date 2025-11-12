#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ceil_div(ll x, ll y) {
    if(x <=0){
        return 0;
    }
    return (x + y -1)/y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> h(N);
        for(auto &x: h) cin >> x;
        vector<ll> a(N);
        for(auto &x: a) cin >> x;
        vector<ll> t(N);
        for(auto &x: t) cin >> x;
        
        vector<pair<ll, ll>> sorted_plants(N, {0,0});
        for(int i=0;i<N;i++){
            ll ti = t[i];
            sorted_plants[ti] = {h[i], a[i]};
        }
        bool impossible = false;
        ll lb =0;
        ll ub = 1e18;
        for(int k=0; k<N-1 && !impossible; k++){
            ll hk = sorted_plants[k].first;
            ll ak = sorted_plants[k].second;
            ll hk1 = sorted_plants[k+1].first;
            ll ak1 = sorted_plants[k+1].second;
            if(ak > ak1){
                ll delta_a = ak - ak1;
                if(hk1 <= hk){
                    continue;
                }
                else{
                    ll x = hk1 - hk;
                    ll lb_candidate = ceil_div(x +1, delta_a);
                    lb = max(lb, lb_candidate);
                }
            }
            else if(ak == ak1){
                if(hk > hk1){
                    continue;
                }
                else{
                    // Impossible
                    impossible = true;
                    break;
                }
            }
            else{
                ll delta_a = ak1 - ak;
                if(hk <= hk1){
                    impossible = true;
                    break;
                }
                else{
                    ll x = hk - hk1 -1;
                    if(x <0){
                        impossible = true;
                        break;
                    }
                    else{
                        ll ub_candidate = x / delta_a;
                        ub = min(ub, ub_candidate);
                    }
                }
            }
        }
        if(impossible || lb > ub){
            cout << "-1\n";
        }
        else{
            cout << lb << "\n";
        }
    }
}