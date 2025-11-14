#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    cout << (n % 2 == 0 ? n * n * (2 * n + 3) / 4 : -(n + 1) * (n + 1) * (2 * n - 1) / 4) << '\n';
}
