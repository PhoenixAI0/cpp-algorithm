#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    int m = (n - 1) / 2;
    int W0 = 0;
    int a[5001];
    int f[5001] = {0};
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <= 49) W0++;
        if(a[i] == 50 || a[i] == 51) f[i] = 1;
    }
    
    if(W0 >= m + 1){
        cout << (n - k + 1) << "\n";
        return 0;
    }
    
    int req = (m + 1) - W0;
    
    int sum = 0;
    for (int i = 0; i < k; i++){
        sum += f[i];
    }
    
    int ans = 0;
    if(sum >= req) ans++;
    
    for (int l = 1; l <= n - k; l++){
        sum = sum - f[l - 1] + f[l + k - 1];
        if(sum >= req) ans++;
    }
    
    cout << ans << "\n";
}