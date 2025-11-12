#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, B;
    cin >> n >> B;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    sort(h.rbegin(), h.rend());
    long long sum = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        sum += h[i];
        cnt++;
        if (sum >= B) break;
    }
    
    cout << cnt << "\n";
}