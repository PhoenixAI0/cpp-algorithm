#include <bits/stdc++.h>
using namespace std;

int main() {
    int a; cin >> a;
    string s = "";
    for (int i = 1; i <= a; i++) {
        s += to_string(i);
    }
    do {
        for (char c : s) {
            cout << setw(5) << c;
        }
        cout << '\n';
    } while (next_permutation(s.begin(), s.end()));
}
