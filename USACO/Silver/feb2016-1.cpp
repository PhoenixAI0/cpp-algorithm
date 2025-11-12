#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    
    int n; 
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    vector<int> A;
    A.reserve(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c[i]; j++) {
            A.push_back(i);
        }
    }
    
    ll ans = LLONG_MAX;
    for (int r = 0; r < n; r++) {
        int pos = int(lower_bound(A.begin(), A.end(), r) - A.begin());
        vector<int> B;
        B.reserve(n);
        for (int i = pos; i < n; i++) {
            B.push_back(A[i]);
        }
        for (int i = 0; i < pos; i++) {
            B.push_back(A[i] + n);
        }
        bool valid = true;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            int dest = r + i;
            if (dest < B[i]) {
                valid = false;
                break;
            }
            int d = dest - B[i];
            cost += (ll)d * d;
        }
        if (valid) {
            ans = min(ans, cost);
        }
    }
    
    cout << ans << "\n";
}