#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    int left = 1, right = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        ll total = 0;
        for (int i = 0; i < n; i++) {
            total += a[i] / mid;
        }
        
        if (total >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";
}
