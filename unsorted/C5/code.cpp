#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[1001];
    string x;
    cin >> x;
    a[0] = x.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = x[a[0] - i] - '0';
    }
    int b[1001];
    string y;
    cin >> y;
    b[0] = y.length();
    for (int i = 1; i <= b[0]; i++) {
        b[i] = y[b[0] - i] - '0';
    }
    int diff[1001];
    diff[0] = max(a[0], b[0]);
    for (int i = 1; i <= diff[0]; i++) {
        diff[i] = 0;
    }
    for (int i = 1; i <= max(a[0], b[0]); i++) {
        diff[i] += a[i] - b[i];
        if (diff[i] < 0) {
            diff[i] += 10;
            diff[i + 1]--;
        }
    }
    while (diff[0] > 1 && diff[diff[0]] == 0) {
        diff[0]--;
    }
    for (int i = diff[0]; i >= 1; i--) {
        cout << diff[i];
    }
    cout << endl;
}