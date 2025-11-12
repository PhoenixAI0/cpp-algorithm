#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        while (a[0].first < b[i].first) {
            ans = max(ans, b[0].second - a[0].second);
            b[0].first -= a[0].first;
            a.erase(a.begin());
        }
        
    }
    
}
