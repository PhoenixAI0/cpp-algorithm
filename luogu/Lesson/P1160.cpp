#include <bits/stdc++.h>
using namespace std;
vector<int> L, R;

void link(int a, int b) {
    R[a] = b;
    L[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    L.resize(n + 1); R.resize(n + 1);

    link(0, 1);
    link(1, 0);
    for (int i = 2; i <= n; ++i) {
        int k, p;
        cin >> k >> p;
        if (p == 0) {
            int prev = L[k];
            link(prev, i);
            link(i, k);
        } else {
            int nxt = R[k];
            link(k, i);
            link(i, nxt);
        }
    }
    vector<int> rem(n + 1);
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (rem[x]) continue;
        link(L[x], R[x]);
        rem[x] = 1;
    }
    for (int x = R[0]; x; x = R[x]) cout << x << " ";
}
