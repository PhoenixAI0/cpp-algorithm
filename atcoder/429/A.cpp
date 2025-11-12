#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cout << (i >= b ? "Too Many Requests" : "OK") << "\n";
    }
}
