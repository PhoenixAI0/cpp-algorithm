#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    int max_val = 0;
    for (int i = 0; i < N; i++){
        cin >> A[i];
        max_val = max(max_val, A[i]);
    }
    
    vector<int> freq(max_val + 1, 0);
    for (int i = 0; i < N; i++){
        freq[A[i]]++;
    }
    
    vector<int> cnt(max_val + 1, 0);
    for (int d = 1; d <= max_val; d++){
        for (int j = d; j <= max_val; j += d){
            cnt[d] += freq[j];
        }
    }
    
    vector<int> ans(max_val + 1, 0);
    for (int d = max_val; d >= 1; d--){
        if (cnt[d] >= K){
            for (int m = d; m <= max_val; m += d){
                ans[m] = max(ans[m], d);
            }
        }
    }
    
    for (int i = 0; i < N; i++){
        cout << ans[A[i]] << "\n";
    }
}