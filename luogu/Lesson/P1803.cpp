#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.second < b.second; });
    int res = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= last) {
            res++;
            last = v[i].second;
        }
    }
    cout << res;
}
