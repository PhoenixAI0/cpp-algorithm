#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> f(n + 1, 0);
        int maxh = 0;
        
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            f[x]++;
            maxh = max(maxh, x);
        }
        
        int ans = 0;
        for(int i=1; i<maxh; i++) if (f[i]>=2) ans += 2;
        cout << ans + 1 << "\n";
    }
}