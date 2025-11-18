#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, l = 0;
    long long sum = 0;

    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > p && l <= r) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << "\n";
}
