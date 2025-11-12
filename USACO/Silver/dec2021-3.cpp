#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<long long> F(M+1, 0), G(M+1, 0);
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        F[a]++;
        G[b]++;
    }
    
    int maxSum = 2 * M;
    vector<long long> A(maxSum+1, 0), B(maxSum+1, 0);
    for (int x = 0; x <= M; x++){
        for (int y = 0; y <= M; y++){
            A[x+y] += F[x] * F[y];
            B[x+y] += G[x] * G[y];
        }
    }
    
    vector<long long> prefixA(maxSum+1, 0), prefixB(maxSum+1, 0);
    
    prefixA[0] = A[0];
    for (int s = 1; s <= maxSum; s++){
        prefixA[s] = prefixA[s-1] + A[s];
    }
    
    prefixB[0] = 0;
    for (int k = 1; k <= maxSum; k++){
        prefixB[k] = prefixB[k-1] + B[k-1];
    }
    
    for (int k = 0; k <= maxSum; k++){
        long long ans = prefixA[k] - prefixB[k];
        cout << ans << "\n";
    }
}