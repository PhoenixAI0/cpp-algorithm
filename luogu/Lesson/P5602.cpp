#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.rbegin(), a.rend());
    
    long long sum = 0;
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        double curr = 1.0 * sum * sum / (i + 1);
        ans = max(ans, curr);
    }
    
    cout << fixed << setprecision(8) << ans << "\n";
}