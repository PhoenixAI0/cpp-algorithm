#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << 3 << endl;
        return 0;
    }

    if(n == 2) {
        cout << 7 << endl;
        return 0;
    }
    
    long long f_prev2 = 3;
    long long f_prev1 = 7;
    long long f_curr;
    
    for(int i = 3; i <= n; i++) {
        f_curr = 2LL * f_prev1 + f_prev2;
        f_prev2 = f_prev1;
        f_prev1 = f_curr;
    }

    cout << f_curr << endl;
}