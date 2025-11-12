#include <bits/stdc++.h>
using namespace std;

static void calc(const int n, const string &status) {
    int a = 0, b = 0;
    for (char c : status) {
        if (c == 'W') a++;
        else if (c == 'L') b++;
        if ((a >= n || b >= n) && abs(a - b) >= 2) {
            cout << a << ':' << b << '\n';
            a = b = 0;
        }
    }
    cout << a << ':' << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string l, status;
    bool flag = false;
    while (!flag && getline(cin, l)) {
        for (char c : l) {
            if (c == 'E') {flag = true; break;}
            if (c == 'W' || c == 'L') status.push_back(c);
        }
    }

    calc(11, status); cout << '\n'; calc(21, status);
}