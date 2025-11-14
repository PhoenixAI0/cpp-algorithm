#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    vector<int> a;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x; cin >> x; a.push_back(x); 
        } else {
            if (a.empty()) cout << "Empty\n";
            else {
                cout << a.back() << "\n";
                a.pop_back();
            }
        }
    }
}
