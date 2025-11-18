#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> b;
    for (int x : a) {
        auto it = lower_bound(b.begin(), b.end(), x);
        if (it == b.end()) b.push_back(x);
        else *it = x;
    }
    cout << b.size() << "\n";
}
