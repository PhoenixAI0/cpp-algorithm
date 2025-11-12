#include <bits/stdc++.h>
using namespace std;

float solve(float x, int i, int n) {
    if (i > n) return x;
    x += (float)i;
    x = sqrt(x);
    return solve(x, i + 1, n);
}

int main() {
    float x; int n; cin >> x >> n;
    cout << fixed << setprecision(2) << solve(x, 1, n) << endl;
}
