#include <bits/stdc++.h>
using namespace std;

vector<int> power(vector<int> perm, long long power) {
    int n = perm.size();
    vector<int> res(n);
    for(int i=0;i<n;i++) res[i] = i;
    
    vector<vector<int>> powers;
    powers.push_back(perm);
    while((1LL << powers.size()) <= power){
        int current = powers.size();
        vector<int> next(n);
        for(int i=0;i<n;i++) next[i] = powers[current-1][powers[current-1][i]];
        powers.push_back(next);
    }
    
    for(int i=0;i<powers.size();i++){
        if(power & (1LL << i)){
            vector<int> temp(n);
            for(int j=0;j<n;j++) temp[j] = res[j];
            for(int j=0;j<n;j++) res[j] = powers[i][temp[j]];
        }
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    long long T;
    cin >> N >> K >> T;
    vector<int> A(K);
    for(auto &x:A) cin >> x;
    
    vector<int> Q(N);
    for(int i=0;i<N;i++) Q[i] = i;
    
    long long m = T / N;
    vector<int> Qm = power(Q, m);
    
    long long r = T % N;
    vector<int> pos_cow(N);
    for(int i=0;i<N;i++) pos_cow[i] = i;
    
    vector<int> temp_cow(N);
    for(int i=0;i<N;i++) temp_cow[i] = pos_cow[Qm[i]];
    pos_cow = temp_cow;
    
    for(long long step=0; step<r; step++){
        long long current_step = step % N;
        vector<int> active(K);
        for(int j=0; j<K; j++) active[j] = (A[j] + current_step) % N;
        int last_cow = pos_cow[active[K-1]];
        for(int j=K-1; j>=1; j--){
            pos_cow[active[j]] = pos_cow[active[j-1]];
        }
        pos_cow[active[0]] = last_cow;
    }
    
    for(int i=0; i<N; i++) cout << pos_cow[i] << (i < N-1 ? ' ':'\n');
}