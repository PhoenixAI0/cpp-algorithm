#include <iostream>
#include <cstring>
using namespace std;

int dp[11][11];

int partitionMN(int m, int n) {
    if (m == 0) return 1;    
    if (n == 0) return 0;    
    if (m < 0) return 0;     

    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    dp[m][n] = partitionMN(m, n-1) + partitionMN(m-n, n);
    return dp[m][n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int M, N;
        cin >> M >> N;

        memset(dp, -1, sizeof(dp));

        cout << partitionMN(M, N) << "\n";
    }
}