#include <bits/stdc++.h>
using namespace std;

void multiply(int (&a)[1001], int (&b)[1001], int (&result)[2002]) {
    int len_a = a[0], len_b = b[0];
    result[0] = len_a + len_b - 1;
    for (int i = 1; i <= 2001; i++) {
        result[i] = 0;
    }
    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            result[i + j - 1] += a[i] * b[j];
        }
    }
    for (int i = 1; i <= result[0]; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    if (result[result[0] + 1] > 0) {
        result[0]++;
    }
}

int main() {
    int result[2002] = {0};
    string x, y;
    cin >> x >> y;
    int a[1001], b[1001];
    a[0] = x.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = x[a[0] - i] - '0';
    }
    b[0] = y.length();
    for (int i = 1; i <= b[0]; i++) {
        b[i] = y[b[0] - i] - '0';
    }
    multiply(a, b, result);
    for (int i = result[0]; i >= 1; i--) {
        cout << result[i];
    }
    cout << '\n';
}