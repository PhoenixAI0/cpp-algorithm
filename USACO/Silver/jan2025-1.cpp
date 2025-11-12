#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; 
    cin >> N;
    vector<int> a(N+1), b(N+1);
    for (int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++){
        cin >> b[i];
    }
    
    long long S1 = 0;
    for (int i = 1; i <= N; i++){
        if(a[i] == b[i]){
            S1 += (long long)(i - 1) * i / 2 + (long long)(N - i) * (N - i + 1) / 2;
        }
    }
    
    vector<vector<int>> posA(N+1), posB(N+1);
    for (int j = 1; j <= N; j++){
        posA[a[j]].push_back(j);
    }
    for (int i = 1; i <= N; i++){
        posB[b[i]].push_back(i);
    }
    
    long long S2 = 0;
    for (int sp = 1; sp <= N; sp++){
        if(posA[sp].empty() || posB[sp].empty()) continue;
        const vector<int> &AList = posA[sp];
        const vector<int> &BList = posB[sp];
        int sz = AList.size();
        vector<long long> prefixA(sz+1, 0);
        for (int idx = 0; idx < sz; idx++){
            prefixA[idx+1] = prefixA[idx] + AList[idx];
        }
        
        for (int i : BList) {
            long long sumForI = 0;
            int t = N + 1 - i;
            int pos_t = upper_bound(AList.begin(), AList.end(), t) - AList.begin();
            
            if(pos_t > 0){
                int pos_i = lower_bound(AList.begin(), AList.begin() + pos_t, i) - AList.begin();
                long long sum_j = prefixA[pos_i];
                sumForI += sum_j;
                int cnt = pos_t - pos_i;
                sumForI += (long long)cnt * i;
            }
            
            if(pos_t < sz){
                int pos_i2 = lower_bound(AList.begin() + pos_t, AList.end(), i) - AList.begin();
                int cnt1 = pos_i2 - pos_t;
                sumForI += (long long)cnt1 * (N + 1 - i);
                
                int cnt2 = sz - pos_i2;
                if(cnt2 > 0){
                    long long sum_j2 = prefixA[sz] - prefixA[pos_i2];
                    sumForI += (long long)(N + 1) * cnt2 - sum_j2;
                }
            }
            S2 += sumForI;
        }
    }
    
    long long ans = S1 + S2;
    cout << ans << "\n";
}