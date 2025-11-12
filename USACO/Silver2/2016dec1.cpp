#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> haybales(n);
    for (int i = 0; i < n; i++) {
        cin >> haybales[i];
    }
    
    sort(haybales.begin(), haybales.end());
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        int left = lower_bound(haybales.begin(), haybales.end(), a) - haybales.begin();
        
        int right = upper_bound(haybales.begin(), haybales.end(), b) - haybales.begin();
        
        cout << right - left << "\n";
    }
}
