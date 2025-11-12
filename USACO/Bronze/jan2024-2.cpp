#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> pad(n + 1);
	vector<bool> vis(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> pad[i].first >> pad[i].second;
	int dir = 1, power = 1, ans = 0;
	for (int reps = 0; reps < 5000000 && 1 <= x && x <= n; ++reps) {
		if (pad[x].first == 1 && power >= pad[x].second && !vis[x]) {
			vis[x] = true;
			++ans;
		}
		if (pad[x].first == 0) {
			dir *= -1;
			power += pad[x].second;
		}
		x += dir * power;
	}
	cout << ans << "\n";
	return 0;
}