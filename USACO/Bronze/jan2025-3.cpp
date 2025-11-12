#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    vector<int> m(n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] == b[i]) m[i] = 1;
    }
    
    vector<ll> p(n + 1);
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + m[i];
    }
    
    ll base = p[n];
    
    vector<ll> h(n + 1);
    
    for(int s = 2; s <= 2 * n; s++){
        int l1 = max(1, s - n);
        int l2 = min(n, s / 2);
        
        if(l2 < l1) continue;
        
        vector<int> x(n + 1);
        for(int i = 1; i <= n; i++){
            int j = s - i;
            if(j >= 1 && j <= n){
                if(a[j] == b[i]){
                    x[i] = 1;
                }
            }
        }
        
        vector<ll> px(n + 1);
        for(int i = 1; i <= n; i++){
            px[i] = px[i - 1] + x[i];
        }
        
        for(int l = l1; l <= l2; l++){
            int r = s - l;
            ll m2 = px[r] - px[l - 1];
            ll m1 = p[r] - p[l - 1];
            ll d = m2 - m1;
            ll nm = base + d;
            
            if(nm >= 0 && nm <= n){
                h[nm]++;
            }
        }
    }
    
    for(int c = 0; c <= n; c++){
        cout << h[c] << "\n";
    }
}