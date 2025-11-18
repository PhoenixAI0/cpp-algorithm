#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<ll> t(n); for (int i = 0; i < n; i++) cin >> t[i];
    ll a = 0, b = 0, ans = 0;

    priority_queue<ll> p;

    for (int i = 0; i < n; i++) {
        a += t[i];

        if (t[i] < 0) {
            p.push(t[i]);
            b += t[i];
            if (p.size() > k - 1) {
                b -= p.top();
                p.pop();
            }
        }
        if (a - b > ans) ans = a - b;
    }

    cout << ans << "\n";
}
