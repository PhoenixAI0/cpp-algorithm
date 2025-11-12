#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    int target = sum - m;
    if (find(a.begin(), a.end(), target) != a.end()) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}
