#include <bits/stdc++.h>
using namespace std;

int main() {
    long long M;
    cin >> M;
    for (long long a = 1; a <= M; a++) {
        long double b = (-1 + sqrtl(1 + 8.0L * M + 4.0L * a * (a - 1))) / 2.0L;
        long long bi = llround(b);
        if (fabsl(b - bi) < 1e-9 && bi > a)
            cout << a << " " << bi << "\n";
    }
}