#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<ll> v(N); for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());

    vector<ll> gap(N - 1);
    vector<ll> pref(N);
    pref[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        gap[i] = v[i + 1] - v[i];
        pref[i + 1] = pref[i] + gap[i];
    }

    deque<int> d;

    for (int i = 0; i < N - K - 1; i++) {
        while (!d.empty() && gap[d.back()] >= gap[i]) d.pop_back();
        d.push_back(i);
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i <= K; i++) {
        while (!d.empty() && d.front() < i) d.pop_front();
        ans = min(ans, pref[i + N - K - 1] - pref[i] + gap[d.front()]);
        if (i < K) {
            while (!d.empty() && gap[d.back()] >= gap[i + N - K - 1]) d.pop_back();
            d.push_back(i + N - K - 1);
        }
    }

    cout << ans << '\n';
}

// PREV SOLUTION
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, k; cin >> n >> k;
//     vector<int> v(n); for (int &x : v) cin >> x;
//     sort(v.begin(), v.end());
//
//     vector<int> diff(n-1);
//     for(int i = 0; i < n-1; i++) diff[i] = v[i+1] - v[i];
//
//     int ans = INT_MAX;
//     for (int i = 0; i <= k; ++i) {
//         int x = INT_MAX;
//         if(k + 1 < n) x = *min_element(diff.begin() + i, diff.begin() + i + n - k - 1);
//         ans = min(ans, v[i + n - k - 1] - v[i] + x);
//     }
//     cout << ans << '\n';
// }
