#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int solve(int x) {
    if (x == 1) return 1;
    if (memo[x] != -1) return memo[x];

    int ans = 1;
    for (int i = 1; i <= x / 2; i++) {
        ans += solve(i);
    }
    
    return memo[x] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    memo.assign(n + 1, -1);
    cout << solve(n) << '\n';
}