#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < b; i++) {
        ans += v[i];
    }
    cout << ans << "\n";
}
