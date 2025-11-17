#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    set<int> s;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a == b) continue;
        s.insert(a); s.insert(b);
    }
    cout << (n - s.size()) << "\n";
}
