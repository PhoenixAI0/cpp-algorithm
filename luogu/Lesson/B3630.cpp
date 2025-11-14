#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> next(n+1);
    for (int i = 1; i <= n; i++) cin >> next[i];
    int h; cin >> h;
    while (h != 0) {
        cout << h << " ";
        h = next[h];
    }
}
