#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    int cost = 0;
    for (int i = 0; i < m; ++i) {
        int unit_price = a[i].first;
        int supply = a[i].second;
        
        if (supply > n) {
            cost += unit_price * n;
            break;
        }
        cost += unit_price * supply;
        n -= supply;
        
        if (n == 0) break;
    }
    cout << cost << "\n";
}