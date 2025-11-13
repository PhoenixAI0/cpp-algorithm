#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = INT_MAX, x = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        x += a;
        ans = min(ans, x);
    }
    cout << (max(0, -ans) + 1) << "\n";
}
