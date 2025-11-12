#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n; ll D, m;
        cin >> n >> D >> m;
        vector<ll> b(n + 1);
        bool zero = false;
        for (int i = 1; i <= n; ++i) {cin >> b[i]; if (b[i] == 0) zero = true;}

        if (D == 1 && zero) {cout << "No\n"; continue;}

        vector<ll> a(n + 1, 0);
        ll Min = 0;
        bool flag = false;

        for (int i = 1; i <= n; ++i) {
            ll prev = a[i - 1];
            if (b[i] == 1) {
                a[i] = ((prev + D - 1) / D) * D;
            } else {
                a[i] = (prev % D != 0) ? prev : prev + 1;
            }
            Min += a[i];
            if (Min > m) {flag = true; break;}
        }
        if (flag) {cout << "No\n"; continue;}

        ll R = m - Min;
        for (int i = n; i >= 1 && R > 0; --i) {
            ll v = a[i];
            ll cap = (i == n ? v + R : min(v + R, a[i + 1]));

            if (b[i] == 1) {
                ll t = (cap / D) * D;
                if (t < v) t = v;
                R -= (t - v);
                a[i] = t;
            } else {
                ll t = cap;
                if (t % D == 0) --t;
                if (t < v) t = v;
                R -= (t - v);
                a[i] = t;
            }
        }

        if (R != 0) {cout << "No\n"; continue;}

        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
}