#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, q; cin >> n >> q;
    priority_queue<ll, vector<ll>, greater<ll>> l;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x; l.push(x);
    }
    ll dmg = 0;
    while (q--) {
        char cmd; cin >> cmd;
        if (cmd == 'A') {
            ll x; cin >> x;
            dmg += x;
            while (!l.empty()) {
                if (l.top() <= dmg) l.pop();
                else break;
            }
        } else {
            ll x; cin >> x;
            if (l.empty()) continue;
            ll val = l.top();
            l.pop();
            l.push(val + x);
        }
    }
    cout << (n - l.size()) << "\n";
}
