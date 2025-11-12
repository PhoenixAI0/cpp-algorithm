#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<bool, string>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<pair<bool, int>> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    int curr = 0, increase;
    for (pair<bool, int> inst : b) {
        curr += ((a[curr].first != inst.first) ? inst.second : n - inst.second);
        curr %= n;
    }
    cout << a[curr].second << "\n";
}
