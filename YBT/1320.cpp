#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> v(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    long long avg = total / n;
    for (int i = 0; i < n; i++) {
        v[i] -= avg;
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] != 0) {
            ans++;
            v[i + 1] += v[i];
            v[i] = 0; 
        }
    }

    cout << ans << "\n";
}