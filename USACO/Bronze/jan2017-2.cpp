#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> v, bool direction) {
    int x = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == v[i].second) continue;
        if (v[i].first == 1 && v[i].second == 2 && direction) {
            x++;
        }
        if (v[i].first == 2 && v[i].second == 3 && direction) {
            x++;
        }
        if (v[i].first == 3 && v[i].second == 1 && direction) {
            x++;
        }
        if (v[i].first == 1 && v[i].second == 3 && !direction) {
            x++;
        }
        if (v[i].first == 3 && v[i].second == 2 && !direction) {
            x++;
        }
        if (v[i].first == 2 && v[i].second == 1 && !direction) {
            x++;
        }
    }
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    cout << max(solve(v, true), solve(v, false)) << "\n";
}
