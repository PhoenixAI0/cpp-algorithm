#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n; cin >> n;
    deque<int> a;
    bool dir = (n % 2 == 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (dir) a.push_front(x);
        else a.push_back(x);
        dir = !dir;
    }
    for (auto x : a) cout << x << " ";
}
