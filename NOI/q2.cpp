#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int m = n/2;
    m += n % 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] <= 0) break;
        ans += a[i];
    }
    cout << ans << "\n";
}
