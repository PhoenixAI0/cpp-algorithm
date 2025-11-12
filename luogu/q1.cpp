#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int last_digit = n % 10;
    int target = m - last_digit;
    if (target < 0) {
        target += 10;
    }
    cout << target << endl;
}