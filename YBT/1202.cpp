#include <bits/stdc++.h>
using namespace std;

static const int MOD = 32767;
static const int MAX_K = 1000000;

int pell[MAX_K + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pell[1] = 1 % MOD;
    pell[2] = 2 % MOD;
    for(int i = 3; i <= MAX_K; i++) {
        pell[i] = (2 * pell[i-1] + pell[i-2]) % MOD;
    }

    int t;  
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        cout << pell[k] << "\n";
    }
}
