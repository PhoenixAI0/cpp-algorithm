#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    //sort by second
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int ans = 0;
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= x) {
            ans++;
            x = v[i].second;
        }
    }
    cout << ans << "\n";
}