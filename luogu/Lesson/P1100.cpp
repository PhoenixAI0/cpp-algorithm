#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n; cin >> n;
    unsigned int result = (n >> 16) | (n << 16);
    cout << result << "\n";
}
