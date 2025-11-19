#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cin >> q;
    int correct = 0;
    for (int i = 0; i < n-1; i++) if (p[i] < p[i+1]) correct++;
    int ans = 0;
    for (int j = 0; j < q; j++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (l != r) {
            set<int> s;
            if (l > 0) s.insert(l-1);
            if (l < n-1) s.insert(l);
            if (r > 0) s.insert(r-1);
            if (r < n-1) s.insert(r);
            for (int idx : s) if (idx >= 0 && idx < n-1 && p[idx] < p[idx+1]) correct--;
            swap(p[l], p[r]);
            for (int idx : s) if (idx >= 0 && idx < n-1 && p[idx] < p[idx+1]) correct++;
        }
        if (correct == n-1) ans++;
    }
    cout << ans << '\n';
    for (auto x : p) cout << x << ' ';
}
