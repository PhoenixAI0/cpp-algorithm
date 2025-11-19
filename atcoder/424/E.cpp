#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; ll k, x; cin >> n >> k >> x;
        map<ld, ll> cnt;
        for (int i = 0; i < n; i++) {
            ld a; cin >> a;
            cnt[a]++;
        }
        while (k > 0) {
            auto it = prev(cnt.end());
            ld a = it->first;
            ll b = it->second;
            ll use = min(k, b);
            if (use == b) cnt.erase(it);
            else it->second -= use;
            cnt[a / 2] += use * 2;
            k -= use;
        }
        ll need = x;
        ld ans = 0;
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
            if (need <= it->second) {
                ans = it->first;
                break;
            }
            need -= it->second;
        }
        cout << fixed << setprecision(20) << ans << "\n";
    }
}
