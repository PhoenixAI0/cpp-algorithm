#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> c(n);
    
    for (int i = 0; i < n; i++) cin >> c[i];
    
    ll ans = LLONG_MAX;
    
    for (int start = 0; start < n; start++) {
        ll energy = 0;
        vector<int> occupied(n, 0);
        
        for (int i = 0; i < n; i++) {
            int idx = (start + i) % n;
            int entering = c[idx];
            
            for (int cow = 0; cow < entering; cow++) {
                int distance = 0;
                int current = idx;
                
                while (occupied[current] > 0) {
                    distance++;
                    current = (current + 1) % n;
                }
                
                occupied[current] = 1;
                energy += (ll)distance * distance;
            }
        }
        
        ans = min(ans, energy);
    }
    
    cout << ans << "\n";
}
