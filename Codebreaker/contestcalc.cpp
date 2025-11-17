#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s; int x;
        cin >> s >> x;
        m[s] = x;
    }
    int c; cin >> c;
    int ans = 0;
    for (int i = 0; i < c; i++) {
        string s; cin >> s;
        ans += m[s];
    }
    ans /= c;
    cout << ans;
}
