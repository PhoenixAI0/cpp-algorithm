#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i + 1;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        cout << a[x] << "\n";
    }
}
