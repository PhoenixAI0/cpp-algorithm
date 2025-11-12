#include <bits/stdc++.h>
using namespace std;

int s[4];
vector<int> problems[4];
int Min;

void dfs(int subject, int idx, int leftTime, int rightTime) {
    if (idx == problems[subject].size()) {
        Min = min(Min, max(leftTime, rightTime));
        return;
    }
    dfs(subject, idx + 1, leftTime + problems[subject][idx], rightTime);
    dfs(subject, idx + 1, leftTime, rightTime + problems[subject][idx]);
}

int main() {
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        problems[i].resize(s[i]);
        for (int j = 0; j < s[i]; j++) cin >> problems[i][j];
        Min = INT_MAX;
        dfs(i, 0, 0, 0);
        ans += Min;
    }
    cout << ans << "\n";
}
