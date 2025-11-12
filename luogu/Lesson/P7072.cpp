#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<ll> low, high;

void move() {
    if (low.empty()) return;
    auto it = prev(low.end());
    high.insert(*it);
    low.erase(it);
}

void balance() {
    while (!low.empty() && !high.empty() && *prev(low.end()) > *high.begin()) {
        ll L = *prev(low.end());
        ll H = *high.begin();
        low.erase(prev(low.end()));
        high.erase(high.begin());
        low.insert(H);
        high.insert(L);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> ans;
    ans.reserve(n);

    for (int i = 1; i <= n; ++i) {
        ll x = a[i-1];
        int k = max(1, (int)floor((long double)i * w / 100));
        low.insert(x);
        while (high.size() < k) move();
        balance();
        ans.push_back(*high.begin());
    }

    for (auto x : ans) cout << x << " "; 
    cout << "\n";
}