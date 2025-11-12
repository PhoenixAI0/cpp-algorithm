#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = 0, maxv = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            maxv = max(maxv, a[i]);
        }
        if (maxv > sum - maxv) {
            cout << fixed << setprecision(1) << static_cast<double>(sum - maxv) << '\n';
        } else {
            cout << fixed << setprecision(1) << static_cast<double>(sum) / 2.0 << '\n';
        }
    }
}