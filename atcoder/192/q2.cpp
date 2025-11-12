#include <bits/stdc++.h>
using namespace std;

long long query(int s, int t) {
    cout << "? " << s << " " << t << "\n";
    cout.flush();
    long long res;
    cin >> res;
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; 
    cin >> N;
    
    int candidate = 1;
    for (int i = 2; i <= N; i++){
        int k = 1;
        while(k == candidate || k == i) {
            k++;
        }
        long long respCandidate = query(candidate, k);
        long long respI         = query(i, k);
        if(respCandidate < respI){
            candidate = i;
        }
    }
    int r = candidate;
    
    vector<long long> val(N+1, 0);
    for (int t = 1; t <= N; t++){
        if(t == r) continue;
        val[t] = query(r, t);
    }
    
    vector<long long> sortedVals;
    for (int t = 1; t <= N; t++){
        if(t == r) continue;
        sortedVals.push_back(val[t]);
    }
    sort(sortedVals.begin(), sortedVals.end());
    
    unordered_map<long long,int> mp;
    for (int j = 0; j < (int)sortedVals.size(); j++){
        mp[sortedVals[j]] = j + 2;
    }
    
    vector<int> P(N+1, 0);
    P[r] = 1;
    for (int t = 1; t <= N; t++){
        if(t == r) continue;
        P[t] = mp[val[t]];
    }
    
    int idx2 = -1, idx3 = -1;
    for (int t = 1; t <= N; t++){
        if(P[t] == 2) idx2 = t;
        if(P[t] == 3) idx3 = t;
    }
    long long resp = query(idx2, idx3);
    long long S3 = sortedVals[1];
    long long S1 = S3 - resp;
    
    vector<long long> S_arr(N+1, 0);
    S_arr[1] = S1;
    S_arr[2] = sortedVals[0];
    for (int i = 3; i <= N; i++){
        S_arr[i] = sortedVals[i - 2];
    }
    vector<long long> A_arr(N+1, 0);
    A_arr[1] = S_arr[1];
    for (int i = 2; i <= N; i++){
        A_arr[i] = S_arr[i] - S_arr[i-1];
    }
    
    cout << "!";
    for (int i = 1; i <= N; i++){
        cout << " " << P[i];
    }
    for (int i = 1; i <= N; i++){
        cout << " " << A_arr[i];
    }
    cout << "\n";
    cout.flush();
}