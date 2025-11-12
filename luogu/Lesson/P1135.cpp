#include <bits/stdc++.h>
using namespace std;

vector<int> k;
vector<int> ans;

void bfs(int start, int end) {
    ans[start - 1] = 0;
    queue<int> q;
    q.push(start - 1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end - 1) return;

        if (curr - k[curr] >= 0 && ans[curr - k[curr]] == -1) {
            ans[curr - k[curr]] = ans[curr] + 1;
            q.push(curr - k[curr]);
        }
        
        if (curr + k[curr] < ans.size() && ans[curr + k[curr]] == -1) {
            ans[curr + k[curr]] = ans[curr] + 1;
            q.push(curr + k[curr]);
        }
    }
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    k.resize(n); for (int i = 0; i < n; i++) cin >> k[i];
    ans.resize(n, -1);
    bfs(a, b);
    cout << ans[b - 1];
}
