#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b; cin >> a >> b; ll squares = 0;
    for (ll i = 0; i < min(a, b); i++) squares += (a - i) * (b - i);
    cout << squares << " " << (a*b*(a+1)*(b+1)/4 - squares) << "\n"; 
}
