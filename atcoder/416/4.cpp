#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];
        
        ll total = 0;
        
        if (N <= 1000) {
            vector<pair<ll, pair<int, int>>> costs;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    ll cost = (A[j] + B[i]) % M;
                    costs.push_back({cost, {i, j}});
                }
            }
            
            sort(costs.begin(), costs.end());
            
            vector<bool> a_used(N, false);
            vector<bool> b_used(N, false);
            
            for (auto& p : costs) {
                ll cost = p.first;
                int b_idx = p.second.first;
                int a_idx = p.second.second;
                
                if (!a_used[a_idx] && !b_used[b_idx]) {
                    a_used[a_idx] = true;
                    b_used[b_idx] = true;
                    total += cost;
                }
            }
        } else {
            sort(A.begin(), A.end());
            multiset<ll> available(A.begin(), A.end());
            
            for (int i = 0; i < N; i++) {
                ll b = B[i];
                ll target = M - b;
                
                auto it = available.lower_bound(target);
                
                ll best_a;
                if (it == available.begin()) {
                    best_a = *available.begin();
                } else {
                    --it;
                    best_a = *it;
                }
                
                total += (best_a + b) % M;
                available.erase(available.find(best_a));
            }
        }
        
        cout << total << '\n';
    }
}
