// https://www.luogu.com.cn/problem/B3614
// Reflections:
// 1. 0 <= x <= 10^64, so we need to use unsigned long long.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

struct stack2 {
    vector<ull> a;
    void push(ull x) {
        a.push_back(x);
    }
    bool pop() {
        if (a.empty()) {
            cout << "Empty\n";
            return false;
        }
        a.pop_back();
        return true;
    }
    ull top() const {
        if (a.empty()) return -1;
        return a.back();
    }
    ull size() const {
        return a.size();
    }
    bool empty() const {
        return a.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        stack2 s;
        for (int i = 0; i < n; ++i) {
            string op;
            cin >> op;
            if (op == "push") {
                ull x; cin >> x;
                s.push(x);
            } else if (op == "pop") {
                s.pop();
            } else if (op == "query") {
                ull res = s.top();
                if (res == -1) cout << "Anguei!\n";
                else cout << res << "\n";
            } else if (op == "size") {
                cout << s.size() << "\n";
            }
        }
    }
}
