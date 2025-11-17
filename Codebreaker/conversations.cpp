// https://codebreaker.xyz/problem/conversations_easy
// Reflections:
// Use stack::find rather than find() in <algorithm>

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    stack<int> s;
    set<int> rem;
    while (n--) {
        while (!s.empty() && rem.find(s.top()) != rem.end()) {
            rem.erase(s.top());
            s.pop();
        }
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x; cin >> x;
            s.push(x);
        } else if (cmd == 2) {
            int x; cin >> x;
            if (s.top() == x) s.pop();
            else rem.insert(x);
        } else if (cmd == 3) {
            s.pop();
        } else {
            cout << (s.empty() ? -1 : s.top()) << "\n";
        }
    }
}
