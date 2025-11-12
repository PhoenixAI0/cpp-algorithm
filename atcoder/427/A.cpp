#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    s.erase(n / 2, 1);
    cout << s << "\n";
}
