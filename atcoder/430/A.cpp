#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c; a[i][j] = (c == '#') ? true : false;
        }
    }
    set<vector<vector<bool>>> b;
    vector<vector<bool>> c(m, vector<bool>(m));
    for (int i = 0; i < (n-m+1); i++) {
        for (int j = 0; j < (n-m+1); j++) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < m; y++) {
                    c[x][y] = a[i + x][j + y];
                }
            }
            b.insert(c);
        }
    }
    cout << b.size();
}
