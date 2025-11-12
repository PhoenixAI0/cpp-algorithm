#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int num = x / (a + b); 
    int remainder = x % (a + b); 
    cout << s * (num * a + min(remainder, a)) << '\n'; 
}
