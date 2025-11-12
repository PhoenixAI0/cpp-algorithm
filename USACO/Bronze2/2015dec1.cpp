#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || a > d) {
        cout << b - a + d - c << '\n';
    } else {
        cout << max(b, d) - min(a, c) << '\n';
    }
}
