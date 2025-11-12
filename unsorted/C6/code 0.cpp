#include <bits/stdc++.h>
using namespace std;

void multiply(int (&a)[2002], int (&b)[2002], int (&result)[2002]) {
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
    int result[2002] = {0}, a[2002] = {0};
    int x; cin >> x;

    result[0] = 1; result[1] = 2;
    a[0] = 1; a[1] = 2;

    for (int i = 1; i < x; i++) {
        int buffer[2002] = {0};
        multiply(result, a, buffer);

        for (int j = 0; j <= buffer[0]; j++) {
            result[j] = buffer[j];
        }
    }

    for (int i = result[0]; i >= 1; i--) {
        cout << result[i];
    }
    cout << '\n';
}