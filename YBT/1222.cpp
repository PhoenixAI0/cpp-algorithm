#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[11][11];

int count(int M, int N) {
    if (M == 0) return 1; 
    if (N == 0) return 0; 
    if (dp[M][N] != -1) return dp[M][N]; 

    if (M < N) {
        dp[M][N] = count(M, M); 
    } else {
        dp[M][N] = count(M, N - 1) + count(M - N, N); 
    }
    return dp[M][N];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, N;
        cin >> M >> N;

        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= 10; j++) {
                dp[i][j] = -1;
            }
        }
        cout << count(M, N) << '\n';
    }
}
