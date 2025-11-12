#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<ll, int> pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]]++;
    }
    vector<ll> vals;
    vector<int> cnts;
    int num_pos = pos.size();
    
    for (const auto& p : pos) {
        vals.push_back(p.first);
        cnts.push_back(p.second);
    }
    
    for (const auto& p : pos) {
        vals.push_back(p.first + m);
        cnts.push_back(p.second);
    }
    
    int sz = vals.size();
    ll result = 0;
    
    vector<ll> prefix(sz + 1, 0);
    for (int i = 0; i < sz; i++) {
        prefix[i + 1] = prefix[i] + cnts[i];
    }
    
    auto find = [&](int start_idx) -> ll {
        int left = start_idx, right = sz;
        while (left < right) {
            int mid = (left + right) / 2;
            ll sum = prefix[mid + 1] - prefix[start_idx];
            if (sum >= c) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left < sz) {
            return prefix[left + 1] - prefix[start_idx];
        }
        return prefix[sz] - prefix[start_idx];
    };
    
    if (vals[0] > 0) {
        ll len = vals[0];
        ll x = find(0);
        result += x * len;
    }
    
    for (int i = 0; i < num_pos; ++i) {
        ll start = vals[i];
        if (start >= m) continue;
        
        ll end = (i + 1 < num_pos) ? vals[i + 1] : vals[0] + m;
        if (end > m) end = m;
        ll len = end - start;
        
        ll x = find(i + 1);
        result += x * len;
    }
    
    cout << result << "\n";
}