#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    for (int i = l - 1; i <= r - 1; i++) {
        if (s[i] == 'x') {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
