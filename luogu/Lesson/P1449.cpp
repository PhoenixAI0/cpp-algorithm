#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> stk;
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '.') {
            stk.push(num);
            num = 0;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            if (c == '+') stk.push(a + b);
            else if (c == '-') stk.push(a - b);
            else if (c == '*') stk.push(a * b);
            else if (c == '/') stk.push(a / b);
        } else if (c == '@') {
            cout << stk.top() << endl;
            break;
        }
    }
}