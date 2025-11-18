#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n+1];
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + 1;
        if (i % 2 == 0) a[i] = min(a[i], a[i/2] + 1);
    }
    cout << a[n];
}
