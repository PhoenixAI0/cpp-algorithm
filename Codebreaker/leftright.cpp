// https://codebreaker.xyz/problem/leftright
// Reflections:
// Maintain two deques of the two halves and swap in O(1) time rather than O(n) rotation.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    deque<int> a, b;

    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x; cin >> x;
            b.push_back(x);
            if (a.size() < b.size()) {
                a.push_back(b.front());
                b.pop_front();
            } else if (a.size() > b.size() + 1) {
                b.push_front(a.back());
                a.pop_back();
            }
        } else {
            if (a.size() == b.size()) {
                swap(a, b);
            } else {
                b.push_back(a.front());
                a.pop_front();
                swap(a, b);
            }
        }
    }
    for (int x : a) cout << x << ' ';
    for (int x : b) cout << x << ' ';
}
