#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < d; i++) {
        ans += a[i];
    }
    cout << ans << "\n";
}