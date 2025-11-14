#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<string, ll>> p(n);
    for (auto &[c, v] : p) {
        cin >> c;
        if (c == "PUSH" || c == "IFZERO") cin >> v;
    }

    vector<ll> s;
    auto f = [&]() {ll v = s.back(); s.pop_back(); return v;};
    ll x = 0;

    for (int i = 0; i >= 0 && i < n;) {
        auto &c = p[i];
        if (c.first == "PUSH") s.push_back(c.second), i++;
        else if (c.first == "STORE") x = f(), i++;
        else if (c.first == "LOAD") s.push_back(x), i++;
        else if (c.first == "PLUS") s.push_back(f() + f()), i++;
        else if (c.first == "TIMES") s.push_back(f() * f()), i++;
        else if (c.first == "IFZERO") i = f() ? i + 1 : c.second;
        else break;
    }
    cout << s.back() << "\n";
}
