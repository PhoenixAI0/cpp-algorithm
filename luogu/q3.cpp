#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, c, k;
    cin >> x >> c >> k;
    for (int i = 0; i < k - 1; i++) {
        x = (x * x + c) % 10000;
    }
    cout << x << endl;
}