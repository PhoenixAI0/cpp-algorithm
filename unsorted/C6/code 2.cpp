#include <bits/stdc++.h>
using namespace std;

void multiply(int (&a)[2002], int (&b)[2002], int (&result)[2002]) {
    int len_a = a[0], len_b = b[0];
    for (int i = 0; i <= 2001; i++) result[i] = 0;

    result[0] = len_a + len_b - 1;
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

    if (result[result[0] + 1] > 0) result[0]++;
}

void add(int (&a)[2002], int (&b)[2002], int (&result)[2002]) {
    int len_a = a[0], len_b = b[0];
    for (int i = 0; i <= 2001; i++) result[i] = 0;

    result[0] = max(len_a, len_b);
    for (int i = 1; i <= result[0]; i++) {
        result[i] += a[i] + b[i];
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    if (result[result[0] + 1] > 0) result[0]++;
}

int main() {
    int result[2002] = {0}, factorial[2002] = {0}, sum[2002] = {0};
    int x;
    cin >> x;

    sum[0] = 1;
    sum[1] = 0;

    for (int i = 1; i <= x; i++) {
        factorial[0] = 1;
        factorial[1] = 1;

        for (int j = 2; j <= i; j++) {
            int temp[2002] = {0};
            int multiplier[2002] = {0};

            multiplier[0] = 0;
            int k = j;
            while (k > 0) {
                multiplier[++multiplier[0]] = k % 10;
                k /= 10;
            }

            multiply(factorial, multiplier, temp);

            for (int k = 0; k <= 2001; k++) {
                factorial[k] = temp[k];
            }
        }

        int temp_sum[2002] = {0};
        add(sum, factorial, temp_sum);

        for (int k = 0; k <= 2001; k++) {
            sum[k] = temp_sum[k];
        }
    }

    for (int i = sum[0]; i >= 1; i--) {
        cout << sum[i];
    }
    cout << '\n';
}