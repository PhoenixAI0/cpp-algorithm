#include <bits/stdc++.h>
using namespace std;

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    int x = 1LL * a.first * b.second + 1LL * b.first * a.second;
    int y = 1LL * a.second * b.second;
    int g = gcd(abs(x), abs(y));
    if (g) {
        x /= g;
        y /= g;
    }
    if (y < 0) {
        y = -y;
        x = -x;
    }
    return {x, y};
}

int main() {
    string s; cin >> s;
    pair<int, int> ans = {0, 1};
    int i = 0, n = s.size();
    while (i < n) {
        int x = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            x = -1;
            i++;
        }
        int a = 0;
        while (i < n && isdigit(s[i])) {
            a = a * 10 + (s[i] - '0');
            i++;
        }
        if (i < n && s[i] == '/') i++;
        int b = 0;
        while (i < n && isdigit(s[i])) {
            b = b * 10 + (s[i] - '0');
            i++;
        }
        ans = add(ans, {x * a, b});
    }
    if (ans.second == 1) cout << ans.first;
    else cout << ans.first << '/' << ans.second;
}
