#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(h.begin(), h.end());
    sort(b.begin(), b.end());
    vector<int> h1(k), b1(k);
    for (int i = 0; i < k; i++) {
        h1[i] = h[i];
        b1[i] = b[m - i - 1];
    }
    reverse(b1.begin(), b1.end());
    bool ans = true;
    for (int i = 0; i < k; i++) {
        if (h1[i] > b1[i]) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << "\n";
}
