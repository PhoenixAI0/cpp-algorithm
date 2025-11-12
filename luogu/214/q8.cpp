#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a_i, a_j, a_k, b_i, b_j, b_k;
    cin >> a_i >> a_j >> a_k >> b_i >> b_j >> b_k;
    long long c_i, c_j, c_k, d_i, d_j, d_k;
    cin >> c_i >> c_j >> c_k >> d_i >> d_j >> d_k;
    long long overlap_i = max(0LL, min(b_i, d_i) - max(a_i, c_i) + 1);
    long long overlap_j = max(0LL, min(b_j, d_j) - max(a_j, c_j) + 1);
    long long overlap_k = max(0LL, min(b_k, d_k) - max(a_k, c_k) + 1);
    cout << overlap_i * overlap_j * overlap_k;
}