#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    
    ll ans = 0;
    
    for (auto& [value, count] : freq) {
        if (count >= 2) {
            ll two = (ll)count * (count - 1) / 2;
            ll one = n - count;
            ans += two * one;
        }
    }
    
    cout << ans << '\n';
}
