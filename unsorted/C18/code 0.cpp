#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    vector<ll> a(z + 2, 0);
    vector<ll> b(z + 2, 0);

    for (int i = 1; i <= x; ++i) {
        a[i] = 1;
    }

    for (int i = x + 1; i <= z + 1; ++i) {
        b[i] = a[i - x] * y;
        a[i] = a[i - 1] + b[i - 2];
    }

    cout << a[z + 1] << "\n";
}