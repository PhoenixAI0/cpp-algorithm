#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    ll N, K; cin >> N >> K;
    
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) cin >> a[i];
    
    ll M = min(N, K + 1), sum = 0, ans = 0;
    priority_queue<ll> rest;
    priority_queue<ll, vector<ll>, greater<ll>> best;
    
    for (ll i = 1; i <= M; i++) {
        ll v = a[i - 1];
        if (v > 0) rest.push(v);
        
        ll need = K - i + 1;
        if (need > i) need = i;
        if (need < 0) need = 0;
        
        while (best.size() < need && !rest.empty()) {
            ll x = rest.top();
            rest.pop();
            sum += x;
            best.push(x);
        }
        
        while (best.size() > need) {
            ll x = best.top();
            best.pop();
            sum -= x;
            rest.push(x);
        }
        
        while (!best.empty() && !rest.empty() && rest.top() > best.top()) {
            ll x = rest.top();
            rest.pop();
            ll y = best.top();
            best.pop();
            sum += x - y;
            best.push(x);
            rest.push(y);
        }
        
        if (sum > ans) ans = sum;
    }
    
    cout << ans;
}
