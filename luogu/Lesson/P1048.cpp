// https://www.luogu.com.cn/problem/P1048#ide
// Reflections:
// 1. Cannot use greedy in partial kapsack problem since each element cannot be split.
// 2. DP array is the most optimal solution
// 3. Recursive DFS for partial credit
// 4. The following is an incorrect code commented out

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m; cin >> t >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
	
	vector<int> dp(t + 1, 0);
	for (int i = 0; i < m; i++) {
		int time = a[i].first;
		int value = a[i].second;
		for (int j = t; j >= time; j--) dp[j] = max(dp[j], dp[j - time] + value);
	}
	cout << dp[t] << "\n";
}

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
