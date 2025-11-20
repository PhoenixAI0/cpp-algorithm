#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> f(vector<pair<ll, ll>> &v) {
    vector<pair<ll, ll>> s = {{0, 0}};
    for (auto &x : v) {
        int n = s.size();
        for (int i = 0; i < n; i++) s.push_back({s[i].first + x.first, s[i].second + x.second});
    }
    return s;
}

int main() {
    ll n, c; cin >> n >> c;
    vector<pair<ll, ll>> a(n / 2), b(n - n / 2);
    for (int i = 0; i < n / 2; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n - n / 2; i++) cin >> b[i].first >> b[i].second;
    vector<pair<ll, ll>> A = f(a), B = f(b);
    sort(B.begin(), B.end());
    vector<ll> M(B.size());
    M[0] = B[0].second;
    for (int i = 1; i < B.size(); i++) M[i] = max(M[i - 1], B[i].second);
    ll z = 0;
    for (auto &x : A) {
        if (x.first > c) continue;
        z = max(z, x.second + M[upper_bound(B.begin(), B.end(), c - x.first, [](ll v, pair<ll, ll> p) {return v < p.first;}) - B.begin() - 1]);
    }
    cout << z;
}