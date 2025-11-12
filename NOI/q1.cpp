#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int breakeven = floor(y / x);
    for (int i : a) {
        if (i > breakeven) {
            ans += y;
        } else {
            ans += x * i;
        }
    }
    cout << ans << "\n";
}
