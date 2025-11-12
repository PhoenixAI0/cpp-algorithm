#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, L, R;
    cin >> n >> L >> R;
    
    long long S = L;
    
    const long long lowBound = -1000000;
    const long long upBound  = 1000000;
    
    long long base = n * lowBound;
    
    long long delta = S - base;
    
    long long maxAdd = upBound - lowBound;
    
    for (int i = 0; i < n; i++) {
        long long add = min(delta, maxAdd);
        long long ai = lowBound + add;
        cout << ai << (i < n - 1 ? " " : "\n");
        delta -= add;
    }
}