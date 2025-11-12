#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> c(N);
    for(int &x : c){
        cin >> x;
    }
    
    vector<int> ci_minus_ti(N);
    for(int i=0; i<N; ++i){
        int ti;
        cin >> ti;
        ci_minus_ti[i] = c[i] - ti;
    }
    
    sort(ci_minus_ti.begin(), ci_minus_ti.end());
    
    while (Q--) {
        int V, S;
        cin >> V >> S;
        
        int idx = upper_bound(ci_minus_ti.begin(), ci_minus_ti.end(), S) - ci_minus_ti.begin();
        int count = N - idx;
        
        if(count >= V){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}