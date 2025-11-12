#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int n, k;
vector<int> current;

void dfs(int depth) {
    if (depth == n) {
        for (auto x : current) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= k; i++) {
        current.push_back(i);
        dfs(depth + 1);
        current.pop_back();
    }
}

int main() {
    cin >> n >> k;
    dfs(0);
}
