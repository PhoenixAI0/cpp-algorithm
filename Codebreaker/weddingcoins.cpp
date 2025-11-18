#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int a[13] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};

int main() {
    ll n; cin >> n;
    ll ans = 0;
    for (int i = 12; i >= 0; i--) {
        ans += n / a[i];
        n %= a[i];
    }
    cout << ans << "\n";
}
