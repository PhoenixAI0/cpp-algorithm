#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<char> a;
    while (n--) {
        string cmd; cin >> cmd;
        if (cmd == "ADD_BACK") {
            char x; cin >> x;
            a.push_back(x);
        } else if (cmd == "ADD_FRONT") {
            char x; cin >> x;
            a.insert(a.begin(), x);
        } else if (cmd == "SNIP_BACK") {
            int y; cin >> y;
            a.erase(a.begin() + y + 1, a.end());
        } else if (cmd == "SNIP_FRONT") {
            int y; cin >> y;
            a.erase(a.begin(), a.begin() + y + 1);
        } else {
            int x; cin >> x; cout << a[x] << "\n";
        }
    }
}
