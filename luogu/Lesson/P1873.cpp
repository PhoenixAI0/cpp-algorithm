#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll m;
    cin >> n >> m;
    
    vector<int> a(n);
    int left = 0, right = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        ll total = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                total += a[i] - mid;
            }
        }
        
        if (total >= m) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";
}
