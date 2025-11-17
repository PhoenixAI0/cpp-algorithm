// https://codebreaker.xyz/problem/cups
// Reflections:
// 1. Sets are const and are immutable.
// 2. Key insight: offset x by -add when pushing to account for the previous rain before it was added.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int q; cin >> q;
    set<ll> s;
    ll add = 0;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            ll x; cin >> x;
            cout << ((s.find(x - add) != s.end()) ? "YES" : "NO") << "\n";
        } else if (cmd == 2) {
            ll x; cin >> x;
            s.insert(x - add);
        } else {
            ll x; cin >> x; add += x;
        }
    }
}
