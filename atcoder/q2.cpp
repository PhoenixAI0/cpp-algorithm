#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    double ratio = static_cast<double>(v[1]) / v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1] * ratio) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
