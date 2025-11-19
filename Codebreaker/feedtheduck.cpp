#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long s = 0, m = LLONG_MAX, l = 0;

    for (auto x : a) {
        s += x;
        while (s >= k) {
            if (s < m) m = s;
            s -= a[l++];
        }
    }

    cout << m;
}