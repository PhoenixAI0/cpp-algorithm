#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    pair<bool, int> a;
    if (n % 2 == 0) {
        a.first = true;
        a.second = n / 2;
    } else {
        a.first = false;
        a.second = n / 2 + 1;
    }
    pair<bool, int> b;
    if (m % 2 == 0) {
        b.first = true;
        b.second = m / 2;
    } else {
        b.first = false;
        b.second = m / 2 + 1;
    }
    if (a.first == b.first) {
        cout << abs(a.second - b.second) - 1 << endl;
    } else {
        cout << abs(a.second + b.second - 1) << endl;
    }
}