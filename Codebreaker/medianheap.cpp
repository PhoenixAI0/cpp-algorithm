#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    priority_queue<int> a; priority_queue<int, vector<int>, greater<int>> b;

    while (n--) {
        string cmd; cin >> cmd;
        if (cmd == "PUSH") {
            int x; cin >> x;
            if (a.empty() || x <= a.top()) a.push(x);
            else b.push(x);
            if (a.size() > b.size() + 1) {
                b.push(a.top());
                a.pop();
            }
            else if (b.size() > a.size()) {
                a.push(b.top());
                b.pop();
            }
        } else {
            a.pop();
            if (a.size() < b.size()) {
                a.push(b.top());
                b.pop();
            }
        }
    }

    vector<int> v;
    while (!a.empty()) {
        v.push_back(a.top());
        a.pop();
    }
    while (!b.empty()) {
        v.push_back(b.top());
        b.pop();
    }
    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";
}
