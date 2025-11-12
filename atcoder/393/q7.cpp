#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long P, Q;
    cin >> N >> P >> Q;
    
    vector<vector<int>> A(N, vector<int>(N));
    vector<long double> vals;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
            vals.push_back(A[i][j]);
        }
    }
    
    sort(vals.begin(), vals.end());
    int tot = N * N;
    long double m;
    if(tot % 2 == 1){
        m = vals[tot/2];
    } else {
        m = vals[(tot/2) - 1];
    }
    
    long double R = (long double) Q / (long double) P;
    
    long double costFull = 0.0L;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            costFull += fabsl((long double)A[i][j] - m);
        }
    }
    
    long double lambda;
    if(costFull < 1e-12L){ 
        lambda = 1.0L;
    } else {
        lambda = (costFull <= R ? 1.0L : R / costFull);
    }
    
    vector<vector<long double>> B(N, vector<long double>(N, 0.0L));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            B[i][j] = (1.0L - lambda) * A[i][j] + lambda * m;
        }
    }
    
    long double U = 0.0L;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 1; j++){
            U += fabsl(B[i][j] - B[i][j+1]);
        }
    }
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < N; j++){
            U += fabsl(B[i][j] - B[i+1][j]);
        }
    }
    
    cout << fixed << setprecision(6) << U << "\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << fixed << setprecision(6) << B[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}