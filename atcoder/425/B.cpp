#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), c(n + 1), e, m;
    int b = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == -1) e.push_back(i);
        else {
            if (c[a[i]]) b = 0;
            c[a[i]] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) if (!c[i]) m.push_back(i);
    int k = e.size();
    if (!b || m.size() != k) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < k; ++i) a[e[i]] = m[i];
    for (int i = 0; i + 1 < k; ++i) if (a[e[i]] == e[i] + 1) swap(a[e[i]], a[e[i + 1]]);
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}
