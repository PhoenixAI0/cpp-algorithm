#include <bits/stdc++.h>
using namespace std;

const int MOD = 32767;
const int MAX_N = 1000000;

int pell(int x, vector<int>& f) {
    if (x <= 2) return x;
    if (f[x] != -1) return f[x];
    return f[x] = (2 * pell(x-1, f) % MOD + pell(x-2, f)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> f(MAX_N + 1, -1);
    f[1] = 1;
    f[2] = 2;

    int n, x;
    cin >> n;

    while (n--) {
        cin >> x;
        if (x > MAX_N) {
            cout << "Input too large\n";
        } else {
            cout << pell(x, f) << '\n';
        }
    }
}