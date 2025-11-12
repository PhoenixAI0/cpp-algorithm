#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    int ans = 0;
    while (n > 0) {
        ans += a[0].first * min(n, a[0].second);
        n -= a[0].second;
        a.erase(a.begin());
    }
    cout << ans;
}