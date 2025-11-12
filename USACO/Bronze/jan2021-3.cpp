#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    
    // Sort cows in ascending order
    sort(cows.begin(), cows.end());
    
    long long ans = 1;
    // Process from largest to smallest cow
    for (int i = n-1; i >= 0; i--) {
        // Count stalls that can fit current cow
        int valid_stalls = 0;
        for (int j = 0; j < n; j++) {
            if (stalls[j] >= cows[i]) {
                valid_stalls++;
            }
        }
        // Subtract the number of stalls that must be used by larger cows
        ans *= (valid_stalls - (n-1-i));
    }
    
    cout << ans << "\n";
}