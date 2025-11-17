#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h; cin >> n >> h;
    vector<int> v(h, 0);
    unordered_map<ll, int> m;
    multiset<int> s;
    for (int i = 0; i < h; i++) s.insert(0);

    while (n--) {
        int op; ll p; cin >> op >> p;
        int& hole = v[(op == 1 ? p : m[p]) % h];
        s.erase(s.find(hole));
        if (op == 1) {
            m[p] = p % h;
            hole++;
        } else {
            hole--;
            m.erase(p);
        }
        s.insert(hole);
        cout << *s.rbegin() << '\n';
    }
}
