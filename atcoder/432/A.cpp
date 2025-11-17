#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3); cin >> a[0] >> a[1] >> a[2];
    sort(a.rbegin(), a.rend());
    for (int x : a) cout << x;
}
