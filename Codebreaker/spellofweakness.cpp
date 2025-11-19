#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; long long d; cin >> n >> d >> k;
    vector<long long> a(n), s(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long t = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        long long x = a[i], y = x - x / 2;
        q.push(y);
        t += y;
        if (q.size() > k) {
            t -= q.top();
            q.pop();
        }
        long long c = s[i + 1] - t;
        if (c <= d) r = i + 1;
    }
    cout << r << "\n";
}