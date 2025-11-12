#include <bits/stdc++.h>
using namespace std;

map<int, int> matchsticks = {
    {0, 6}, {1, 2}, {2, 5}, {3, 5}, {4, 4},
    {5, 5}, {6, 6}, {7, 3}, {8, 7}, {9, 6}
};

int count(int num) {
    if (num == 0) return matchsticks[0];
    int total = 0;
    while (num > 0) {
        total += matchsticks[num % 10];
        num /= 10;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    n -= 4;
    int ans = 0;
    for (int A = 0; A <= 2000; A++) {
        int cntA = count(A);
        if (cntA > n) continue;
        for (int B = 0; B <= 2000; B++) {
            int cntB = count(B);
            if (cntA + cntB > n) continue;
            int C = A + B;
            int cntC = count(C);
            if (cntA + cntB + cntC == n) ans++;
        }
    }
    cout << ans << "\n";
}
