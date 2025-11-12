#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[1001];
    string s;
    cin >> s;
    a[0] = s.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
    for (int i = s.length(); i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
}