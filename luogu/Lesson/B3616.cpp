#include <bits/stdc++.h>
using namespace std;

struct queue2 {
    int* arr;
    int front;
    int rear;
    int sz;
    int capacity;
    queue2(int size) {
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = 0;
        sz = 0;
    }
    void push(int x) {
        if (sz < capacity) {
            arr[rear] = x;
            rear = (rear + 1) % capacity;
            sz++;
        }
    }
    void pop() {
        if (sz > 0) {
            front = (front + 1) % capacity;
            sz--;
        } else {
            cout << "ERR_CANNOT_POP\n";
        }
    }
    int query() {
        if (sz > 0) {
            return arr[front];
        }
        return -1;
    }
    int size() {
        return sz;
    }
};

int main() {
    int n;
    cin >> n;
    queue2 q2(n);
    for (int i = 0; i < n; ++i) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            q2.push(x);
        } else if (cmd == 2) {
            q2.pop();
        } else if (cmd == 3) {
            int res = q2.query();
            if (res == -1) cout << "ERR_CANNOT_QUERY\n";
            else cout << res << "\n";
        } else if (cmd == 4) {
            cout << q2.size() << "\n";
        }
    }
}
