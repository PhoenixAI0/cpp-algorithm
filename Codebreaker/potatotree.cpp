#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        p[i] = s.size();
    }
    while (q--) {
        int x; cin >> x; cout << p[x-1] << " ";
    }
}
