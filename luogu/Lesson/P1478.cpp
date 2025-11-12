// https://www.luogu.com.cn/problem/P1478#ide
// Reflections:
// 1. Simple greedy algorithm
// 2. Filter the items that are too high at cin-time for speed.
// 3. qSort the items, then filter.fz

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, a, b; cin >> n >> s >> a >> b;
    int c = a + b;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x <= c) {
            v.push_back(y);
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while (s > 0) {
        s -= v[ans];
        if (s < 0) break;
        ans++;
    }
    cout << ans;
}
