#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int x;
vector<pair<int, int>> prefers;
vector<bool> visited;
int total = 0;

void dfs(int pos) {
    if (pos == x) {
        total++;
        return;
    }
    
    int a = prefers[pos].first;
    int b = prefers[pos].second;
    
    if (a == b) {
        if (!visited[a]) {
            visited[a] = true;
            dfs(pos + 1);
            visited[a] = false;
        }
    } else {
        if (!visited[a]) {
            visited[a] = true;
            dfs(pos + 1);
            visited[a] = false;
        }
        if (!visited[b]) {
            visited[b] = true;
            dfs(pos + 1);
            visited[b] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> x;
    prefers.resize(x);
    for (int i = 0; i < x; ++i) {
        cin >> prefers[i].first >> prefers[i].second;
    }
    visited.resize(x + 1, false);
    
    dfs(0);
    cout << total << endl;
}