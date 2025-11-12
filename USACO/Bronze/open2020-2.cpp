#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++) {
        int x, s; cin >> x >> s;
        cows.push_back({x, s});
    }
    sort(cows.begin(), cows.end());
    
    // Find R: minimum distance between sick and healthy cow - 1
    int R = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        if (cows[i].second != cows[i+1].second) {
            R = min(R, cows[i+1].first - cows[i].first);
        }
    }
    if (R == INT_MAX) R = 0;
    
    // Count groups of infected cows
    int ans = 0;
    bool in_group = false;
    for (int i = 0; i < n; i++) {
        if (cows[i].second == 1) {  // if current cow is infected
            if (!in_group) {  // start of new group
                ans++;
                in_group = true;
            }
        }
        if (i < n-1 && cows[i+1].first - cows[i].first >= R) {
            in_group = false;  // end current group if distance to next cow >= R
        }
    }
    cout << ans << "\n";
}