// https://codebreaker.xyz/problem/catlunch
// Reflections:
// 1. Initial greedy method does not work. The cat can eat a negative one for larger positive fishes in the future
// 2. You can skip at most k-1 fishes, to skip k-1 negative fishes.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<ll> t(n); for (int i = 0; i < n; i++) cin >> t[i];
    ll a = 0, b = 0, ans = 0;

    priority_queue<ll> p;

    for (int i = 0; i < n; i++) {
        a += t[i];

        if (t[i] < 0) {
            p.push(t[i]);
            b += t[i];
            if (p.size() > k - 1) {
                b -= p.top();
                p.pop();
            }
        }
        if (a - b > ans) ans = a - b;
    }

    cout << ans << "\n";
}


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int n, k;
//     cin >> n >> k;
//     vector<ll> t(n);
//     for (int i = 0; i < n; i++) cin >> t[i];
//
//     multiset<ll> s;
//     ll sum = 0, eaten = 0, ans = 0;
//
//     int idx = 0;
//     for (; idx < min(k, n); idx++) {
//         s.insert(t[idx]);
//         if (t[idx] > 0) sum += t[idx];
//     }
//     ans = sum;
//
//     while (idx < n && !s.empty()) {
//         auto it = prev(s.end());
//         ll x = *it;
//         s.erase(it);
//         if (x > 0) sum -= x;
//         eaten += x;
//
//         s.insert(t[idx]);
//         if (t[idx] > 0) sum += t[idx];
//         idx++;
//
//         ans = max(ans, eaten + sum);
//     }
//
//     ans = max(ans, eaten + sum);
//     cout << ans << "\n";
// }
