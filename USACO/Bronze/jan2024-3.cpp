#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> a(N);
    for (auto &x: a) cin >>x;
    
    vector<ll> b(N, 0);
    for (int i=0; i<N; i++) b[i] = a[N-1-i];
    
    ll total_operations =0;
    
    for (int k=0; k<N; k++){
        ll c_k = -b[k];
        if (k+1 < N) c_k += 2*b[k+1];
        if (k+2 < N) c_k -= b[k+2];
        total_operations += abs(c_k);
    }
    
    cout << total_operations << "\n";
}