#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N, C; cin >> N >> C;
    set<pair<ll, int>> pool;
    for (int i = 1; i <= N; ++i) {
        ll x;
        cin >> x;
        pool.insert({x, i});
    }

    while (C--) {
        ll pick;
        cin >> pick;

        auto hi = pool.lower_bound({pick, 0});
        if (hi == pool.begin()) {
            cout << (*hi).second << '\n';
            pool.erase(hi);
            continue;
        }

        auto lo = prev(hi);
        if (hi == pool.end()) {
            cout << (*lo).second << '\n';
            pool.erase(lo);
            continue;
        }

        ll dh = (*hi).first - pick;
        ll dl = pick - (*lo).first;
        if (dl <= dh) {
            cout << (*lo).second << '\n';
            pool.erase(lo);
        } else {
            cout << (*hi).second << '\n';
            pool.erase(hi);
        }
    }
}
