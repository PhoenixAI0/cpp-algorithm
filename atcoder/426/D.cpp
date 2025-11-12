#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static ll f(const string& s, char a) {
    int n = s.size();
    ll bad = 0, x = 0;
    for (char c : s) if (c == a) bad++;
    ll tot = bad;
    int i = 0, j = n - 1;
    while (true) {
        while (i <= j && s[i] == a) {bad--; i++;}
        while (i <= j && s[j] == a) {bad--; j--;}
        if (!bad) break;
        int l = 0; while (i + l <= j && s[i + l] != a) l++;
        int r = 0; while (j - r >= i && s[j - r] != a) r++;
        if (l <= r) {x += l; i += l;}
        else {x += r; j -= r;}
    }
    return tot + 2 * x;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        cout << min(f(s, '0'), f(s, '1')) << "\n";
    }
}
