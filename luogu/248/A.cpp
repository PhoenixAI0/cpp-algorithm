#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    if (b != 1) n -= b - 1;
    int ans = (n / (a+1)) * a;
    if (n % (a+1) != 0) ans += min(n % (a+1), a);
    cout << ans << "\n";
}
