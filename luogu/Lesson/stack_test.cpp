#include <bits/stdc++.h>
using namespace std;

struct stack2 {
    int *arr;
    int top_value;
    int size;
    stack2(int size) {
        this->size = size;
        arr = new int[size];
        top_value = -1;
    }
    void push(int x) {
        arr[++top_value] = x;
    }
    void pop() {
        top_value--;
    }
    int top() {
        return arr[top_value];
    }
};

int main() {
    stack2 s(100000);
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            s.push(x);
        } else if (op == 2) {
            cout << s.top() << endl;
            s.pop();
        }
    }
}
