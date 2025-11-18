#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int a, b, c; cin >> a >> b >> c;
    s.insert(a); s.insert(b); s.insert(c);
    cout << (s.size() < 3 ? "Yes" : "No");
}
