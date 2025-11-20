#include <bits/stdc++.h>
using namespace std;
map<char, pair<char, char>> m;

void f(char x) {
    cout << x;
    if (m[x].first != '*') f(m[x].first);
    if (m[x].second != '*') f(m[x].second);
}

int main() {
    int n; cin >> n; char x;
    for (int i = 0; i < n; i++) {
        char a, b, c; cin >> a >> b >> c;
        if (i == 0) x = a;
        m[a] = make_pair(b, c);
    }
    f(x);
}
