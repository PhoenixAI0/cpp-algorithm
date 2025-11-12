#include <bits/stdc++.h>
using namespace std;

int n, r;

void dfs(int start, int need, vector<int>& cur) {
    if (need == 0) {
        for (int i = 0; i < (int)cur.size(); ++i) {
            cout << setw(3) << cur[i];
        }
        cout << '\n';
        return;
    }
    for (int x = start; x <= n - need + 1; ++x) {
        cur.push_back(x);
        dfs(x + 1, need - 1, cur);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;

    if (r == 0) return 0;

    vector<int> cur;
    cur.reserve(r);
    dfs(1, r, cur);
}