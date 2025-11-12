#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n; cin >> n;
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    map<pair<int, int>, vector<int>> m;
    int x = 0, y = 0, time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].second; j++) {
            m[{x, y}].push_back(time);
            if (a[i].first == 'N') {
                y++;
            }
            else if (a[i].first == 'S') {
                y--;
            }
            else if (a[i].first == 'E') {
                x++;
            }
            else if (a[i].first == 'W') {
                x--;
            }
            time++;
        }
    }
    int ans = INT_MAX;
    for (auto &p : m) {
        if (p.second.size() > 1) {
            sort(p.second.begin(), p.second.end());
            for (int i = 1; i < p.second.size(); i++) {
                ans = min(ans, p.second[i] - p.second[i-1]);
            }
        }
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
}
