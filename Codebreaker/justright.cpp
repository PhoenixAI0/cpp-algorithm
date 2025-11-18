#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; ll k; cin >> n >> k;
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; s[i + 1] = s[i] + x;
    }
    priority_queue<tuple<ll, int, int>> pq;
    for (int i = 0; i < n; i++) pq.push({s[n] - s[i], i, n});
    ll res = 0;
    while (k-- && !pq.empty()) {
        auto [sum, l, r] = pq.top();
        pq.pop();
        res = sum;
        if (r - 1 > l) pq.push({s[r - 1] - s[l], l, r - 1});
    }
    cout << res << '\n';
}
