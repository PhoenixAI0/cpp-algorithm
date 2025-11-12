#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    static long long S[31][31] = {0};
    
    S[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            S[i][j] = j * S[i-1][j] + S[i-1][j-1];
        }
    }
    
    cout << S[n][k] << endl;
}