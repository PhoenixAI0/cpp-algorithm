#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dist(n + 1, -1);
    
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr == n) {
            cout << dist[curr];
            return 0;
        }
        
        if (curr + 1 <= n && dist[curr + 1] == -1) {
            dist[curr + 1] = dist[curr] + 1;
            q.push(curr + 1);
        }
        
        if (curr - 1 >= 1 && dist[curr - 1] == -1) {
            dist[curr - 1] = dist[curr] + 1;
            q.push(curr - 1);
        }
        
        if (curr * 2 <= n && dist[curr * 2] == -1) {
            dist[curr * 2] = dist[curr] + 1;
            q.push(curr * 2);
        }
    }
    
    cout << dist[n];
}
