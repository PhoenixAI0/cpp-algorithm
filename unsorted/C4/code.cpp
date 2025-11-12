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
    int sum[1001];
    sum[0] = max(a[0], b[0]);
    for (int i = 1; i <= sum[0]; i++) {
        sum[i] = 0;
    }
    for (int i = 1; i <= max(a[0], b[0]); i++) {
        sum[i] += a[i] + b[i];
        if (sum[i] >= 10) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
    if (sum[sum[0] + 1] > 0) {
        sum[0]++;
    }
    for (int i = sum[0]; i >= 1; i--) {
        cout << sum[i];
    }
    cout << endl;
}