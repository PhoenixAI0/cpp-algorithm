#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int q; cin >> q;
    queue<int> a;
    unordered_map<int,int> left;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x; cin >> x; 
            a.push(x);
        } else if (cmd == 2) {
            int x; cin >> x;
            left[x]++;
        } else {
            while (!a.empty()) {
                int front = a.front();
                auto it = left.find(front);
                if (it == left.end()) break;
                if (--(it->second) == 0) left.erase(it);
                a.pop();
            }
            if (!a.empty()) {
                int x = a.front(); 
                a.pop();
                cout << x << " ";
            }
        }
    }
}