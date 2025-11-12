#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    stack<char> rev;
    for (char c : s) {
        rev.push(c);
    }
    while (!rev.empty()) {
        cout << rev.top();
        rev.pop();
    }
    cout << "\n";
}
