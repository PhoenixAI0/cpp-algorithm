#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    while (s[0] == '0') next_permutation(s.begin(), s.end());
    cout << s;
}
