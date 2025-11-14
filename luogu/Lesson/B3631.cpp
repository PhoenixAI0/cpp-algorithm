// https://www.luogu.com.cn/problem/B3631
// Reflections:
// 1. Take note of how to erase an element from the list. next[x] = next[next[x]];
// 2. Erase syntax for map is map.erase(x);
// 3. Don't use find to check if an element exists in the map. Just use map[x] to get the value.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    map<int, int> next;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, y; cin >> x >> y;
            if (next.find(x) != next.end()) next[y] = next[x];
            next[x] = y;
        }
        else if (cmd == 2) {
            int x; cin >> x; cout << (next.find(x) != next.end() ? next[x] : 0) << "\n";
        }
        else {
            int x; cin >> x;
            int y = next[x];
            next[x] = next[y];
            next.erase(y);
        }
    }
}
