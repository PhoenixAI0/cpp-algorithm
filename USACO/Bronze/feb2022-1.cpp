#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int total = 0;
        for (int i = 0; i < n; i++) total += a[i];
        
        int min_operations = n - 1;
        
        for (int k = 1; k <= n; k++) {
            if (total % k != 0) continue;
            int target = total / k;
            int current_sum = 0;
            bool valid = true;
            for (int num : a) {
                current_sum += num;
                if (current_sum > target) {
                    valid = false;
                    break;
                } else if (current_sum == target) {
                    current_sum = 0;
                }
            }
            if (valid && current_sum == 0) {
                min_operations = min(min_operations, n - k);
            }
        }
        
        cout << min_operations << '\n';
    }
}