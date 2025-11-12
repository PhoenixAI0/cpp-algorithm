#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r = (r - l) / 2;
        
        auto isGood = [&](int d) -> bool {
            if (d > r) return false;
            int best = INT_MAX;
            for (auto& [val, positions] : pos) {
                auto it_low = lower_bound(positions.begin(), positions.end(), l);
                auto it_high = lower_bound(positions.begin(), positions.end(), l + 2*r);
                if (it_high - it_low < 2) continue;
                
                for (auto it = it_low; it != it_high; ++it) {
                    auto it2 = lower_bound(it + 1, it_high, *it + d);
                    if (it2 != it_high && *it2 == *it + d) {
                        int x = *it - l;
                        if (x < d && d <= r) {
                            best = min(best, x);
                        }
                    }
                }
            }
            return best < d;
        };
        
        int ans = 0;
        for (int d = 1; d <= r; d++) {
            int chain = 0;
            int curr = d;
            while (curr <= r && isGood(curr)) {
                chain++;
                curr *= 2;
            }
            ans = max(ans, chain);
        }
        cout << ans << '\n';
    }
}