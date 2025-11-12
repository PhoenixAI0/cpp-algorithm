#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;  
    string S;
    cin >> S;  
    vector<ll> a(N); 
    for (ll& milk : a) cin >> milk;  

    vector<bool> bad_L(N), bad_R(N);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R' && S[(i + 1) % N] == 'L') {
            bad_L[i] = true;
            bad_R[(i + 1) % N] = true;  
        }
    }

    ll totalMilk = accumulate(a.begin(), a.end(), 0LL);

    for (int i = 0; i < N; i++) {
        ll spilledMilk = 0;

        if (bad_L[i]) {
            int j = (i - 1 + N) % N;  
            while (S[j] == 'R') {    
                spilledMilk += a[j--];  
                if (j < 0) j += N;      
            }
        }

        if (bad_R[i]) {
            int j = (i + 1) % N;  
            while (S[j] == 'L') { 
                spilledMilk += a[j++];  
                if (j >= N) j -= N;     
            }
        }

        totalMilk -= min(spilledMilk, (ll)M);
    }

    cout << totalMilk << endl;
}