#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int>> directions = {
    {1, 1},
    {1, 0},
    {1, -1},
    {0, 1},
    {0, -1},
    {-1, 1},
    {-1, 0},
    {-1, -1}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '?') {
                int cnt = 0;
                for (pair<int, int> direction : directions) {
                    int ni = i + direction.first;
                    int nj = j + direction.second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (v[ni][nj] == '*') cnt++;
                    }
                }
                v[i][j] = '0' + cnt;
            }
            cout << v[i][j];
        }
        cout << "\n";
    }
}