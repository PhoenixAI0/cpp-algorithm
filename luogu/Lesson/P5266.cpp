#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    unordered_map<string, long long> a;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            string x; long long y; cin >> x >> y;
            a[x] = y;
            cout << "OK\n";
        } else if (op == 2) {
            string s; cin >> s;
            auto it = a.find(s);
            cout << (it == a.end() ? "Not found" : to_string(it->second)) << '\n';
        } else if (op == 3) {
            string s; cin >> s;
            cout << (a.erase(s) ? "Deleted successfully" : "Not found") << '\n';
        } else {
            cout << a.size() << '\n';
        }
    }
}
