#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    ll q; cin >> q;
    deque<ll> a;
    while (q--) {
        ll cmd; cin >> cmd;
        if (cmd == 1) {
            ll x; cin >> x; a.push_back(x);
        } else if (cmd == 2) {
            a.pop_back();
        } else {
            cout << a.front() << "\n";
            a.pop_front();
        }
    }
}
