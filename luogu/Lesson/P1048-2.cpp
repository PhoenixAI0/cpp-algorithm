// #include <bits/stdc++.h>
// using namespace std;
// 
// bool compare(pair<int, int> a, pair<int, int> b) {
//     return a.second * b.first > a.first * b.second;
// }
// 
// int main() {
//     int t, m; cin >> t >> m;
//     vector<pair<int, int>> a;
//     for (int i = 0; i < m; i++) {
//         int b, c; cin >> b >> c;
//         if (b > t) continue;
//         a.push_back(make_pair(b, c));
//     }
//     sort(a.begin(), a.end(), compare);
//     int ans = 0;
//     for (auto x : a) {
//         t -= x.first;
//         if (t < 0) break;
//         ans += x.second;
//     }
//     cout << ans;
// }
