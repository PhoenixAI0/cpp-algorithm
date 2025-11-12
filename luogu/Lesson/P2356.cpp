#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                flag = true;
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += a[i][k];
                }
                for (int k = 0; k < n; k++) {
                    sum += a[k][j];
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << (flag ? to_string(ans) : "Bad Game!") << "\n";
}
