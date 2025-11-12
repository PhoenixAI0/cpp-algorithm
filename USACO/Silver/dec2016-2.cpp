#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    
    int N;
    cin >> N;
    unordered_map<string, int> freq;
    for (int i = 0; i < N; i++) {
        string city, state;
        cin >> city >> state;
        string prefix = city.substr(0, 2);
        if (prefix == state) continue;
        string key = prefix + state;
        freq[key]++;
    }
    
    ll ans = 0;
    for (const auto &entry : freq) {
        string key = entry.first;
        string rev = key.substr(2, 2) + key.substr(0, 2);
        if (freq.find(rev) != freq.end() && key < rev)
            ans += (ll)entry.second * freq[rev];
    }
    
    cout << ans;
}