#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n); set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 10) s.insert(i);
    }
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int l, r; cin >> l >> r; l--; r--;
            auto it = s.lower_bound(l);
            while (it != s.end() && *it <= r) {
                int i = *it;
                it++;
                a[i] = f(a[i]);
                if (a[i] < 10) s.erase(i);
            }
        } else {
            int x; cin >> x; cout << a[--x] << "\n";
        }
    }
}
