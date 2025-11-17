#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x; cout << x << "\n";
    map<int, int> a;
    for (int i = 0; i < x; i++) {
        int tmp; cin >> tmp;
        a[tmp]++;
    }
    int y; cin >> y;
    for (int i = 0; i < y; i++) {
        int tmp; cin >> tmp;
        a[tmp]++;
    }
    for (auto x : a) {
        if (x.second == 2) cout << x.first << " ";
    }
    cout << "\n";
    for (auto x : a) {
        cout << x.first << " ";
    }
    cout << "\n";
}
