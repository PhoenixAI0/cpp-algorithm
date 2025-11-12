#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    ll totalW = 0, base = 0;
    vector<pair<int, int>> items; items.reserve(n);

    for (int i = 0; i < n; ++i) {
        ll w, h, b; 
        cin >> w >> h >> b;
        totalW += w; 
        base += b;
        if (h > b) items.push_back({(int)w, (int)(h - b)});
    }

    ll cap = totalW / 2;
    vector<ll> dp(cap + 1, 0);

    for (auto [w, v] : items) {
        if (w > cap) continue;
        for (ll c = cap; c >= w; --c)
            dp[c] = max(dp[c], dp[c - w] + v);
    }

    cout << base + dp[cap] << '\n';
}