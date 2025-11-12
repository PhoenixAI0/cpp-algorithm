#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        pq.push(x);
    }
    int res = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        res += a + b;
        pq.push(a + b);
    }
    cout << res;
}
