#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n), b(n), g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i];
    }
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        int x = i;
        int score = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == x) x = b[j];
            else if (b[j] == x) x = a[j];
            if (x == g[j]) score++;
        }
        ans = max(ans, score);
    }
    cout << ans << "\n";
}