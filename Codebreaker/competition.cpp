#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> A(n);
    for (auto& x : A) cin >> x;

    ll ans = 0;
    vector<ll> C(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += x;
        C[i] = A[i] - x;
    }

    sort(C.rbegin(), C.rend());
    for (int i = 0; i < a; i++) ans += C[i];

    cout << ans;
}
