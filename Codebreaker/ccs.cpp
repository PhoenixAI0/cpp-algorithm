#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    set<int> s;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "WAKE") {
            int x; cin >> x;
            s.erase(x);
        } else if (cmd == "SLEEP") {
            int x; cin >> x;
            s.insert(x);
        } else {
            int x, y; cin >> x >> y;
            auto it = s.lower_bound(x);
            cout << (it == s.end() || *it > y ? "YES\n" : "NO\n");
        }
    }
}
