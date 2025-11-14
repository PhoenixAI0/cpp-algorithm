#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<map<int, int>> a(n);
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int i, j, k; cin >> i >> j >> k; i--; j--;
            if (k != 0) a[i][j] = k;
            else a[i].erase(j);
        } else {
            int i, j; cin >> i >> j; i--; j--;
            cout << a[i][j] << "\n";
        }
    }
}