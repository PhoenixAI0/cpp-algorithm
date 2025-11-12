#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    
    vector<int> delta(n);
    for (int i = 0; i < n; ++i) {
        delta[i] = p[i] - t[i];
    }
    
    int prev = 0, result = 0;
    for (int d : delta) {
        result += abs(d - prev);
        prev = d;
    }
    result += abs(0 - prev);
    result /= 2;
    
    cout << result << "\n";
}