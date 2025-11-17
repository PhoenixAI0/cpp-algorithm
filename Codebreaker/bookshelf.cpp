#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    deque<int> q;
    unordered_map<int, deque<ll>> pos;
    ll a = 0, b = -1;

    while (t--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x; cin >> x;
            ll id;
            if (q.empty()) {
                a = b = 0; id = 0;
            } else id = --a;
            q.push_front(x);
            pos[x].push_front(id);
        } else if (cmd == 2) {
            int x; cin >> x;
            ll id;
            if (q.empty()) {
                a = b = 0; id = 0;
            } else id = ++b;
            q.push_back(x);
            pos[x].push_back(id);
        } else if (cmd == 3) {
            int x = q.front();
            q.pop_front();
            pos[x].pop_front();
            if (pos[x].empty()) pos.erase(x);
            if (q.empty()) {
                a = 0; b = -1;
            } else {
                int y = q.front();
                a = pos[y].front();
            }
        } else if (cmd == 4) {
            int x = q.back();
            q.pop_back();
            pos[x].pop_back();
            if (pos[x].empty()) pos.erase(x);
            if (q.empty()) {
                a = 0; b = -1;
            } else {
                int y = q.back();
                b = pos[y].back();
            }
        } else if (cmd == 5) {
            int x; cin >> x;
            cout << (pos[x].front() - a + 1) << '\n';
        } else {
            int x; cin >> x;
            cout << (b - pos[x].back() + 1) << '\n';
        }
    }
}
