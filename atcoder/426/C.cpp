#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    map<int, int> m;
    for (int i = 1; i <= n; i++) m[i] = 1;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        int ans = 0;
        auto it = m.upper_bound(x);
        for (auto j = m.begin(); j != it; j++) ans += (*j).second;
        m.erase(m.begin(), it);
        m[y] += ans;
        
        cout << ans << "\n";
    }
}
