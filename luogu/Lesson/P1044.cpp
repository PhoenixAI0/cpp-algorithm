#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<unsigned long long> c(n + 1, 0);
    c[0] = 1;
    for (int k = 1; k <= n; ++k) {
        unsigned long long s = 0;
        for (int i = 0; i < k; ++i) s += c[i] * c[k - 1 - i];
        c[k] = s;
    }

    cout << c[n] << '\n';
}
