#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    int a, b;
    while (t--) {
        int cmd; cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> a >> b;
                cout << (a & b) << "\n";
                break;
            case 2:
                cin >> a >> b;
                cout << (a | b) << "\n";
                break;
            case 3:
                cin >> a >> b;
                cout << (a ^ b) << "\n";
                break;
            case 4:
                cin >> a;
                cout << (~a) << "\n";
                break;
        }
    }
}
