#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);
    vector<int> out;
    while (!q.empty()) {
        for (int i = 1; i < m; ++i) {
            q.push(q.front());
            q.pop();
        }
        out.push_back(q.front());
        q.pop();
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << out[i];
    }
}
