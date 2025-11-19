#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {string s; cin >> s; if (s == "chugga") ans++;}
    cout << (ans % 2 == 0 ? "CHOO choo" : "choo CHOO") << "\n";

}
