#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    const int MAX = 5000000;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++){
        if(isPrime[i]){
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    
    while(T--){
        int N;
        cin >> N;
        int a;
        cin >> a;
        for (int i = 1; i < N; i++){
            int dummy;
            cin >> dummy;
        }
        
        if(a == 1 || isPrime[a])
            cout << "Farmer John" << "\n";
        else {
            if(a % 4 == 0)
                cout << "Farmer Nhoj" << "\n";
            else
                cout << "Farmer John" << "\n";
        }
    }
    
    return 0;
}