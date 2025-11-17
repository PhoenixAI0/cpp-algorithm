#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    unordered_map<int, int> next;

    void insert(int x, int y) {
        if (next.find(x) != next.end()) next[y] = next[x];
        next[x] = y;
    }

    int nxt(int x) {
        auto it = next.find(x);
        return it != next.end() ? it->second : 0;
    }

    void erase_after(int x) {
        int y = next[x];
        next[x] = next[y];
        next.erase(y);
    }
};

int main() {
    int n, m; 
    cin >> n >> m;

    LinkedList list;

    for (int i = 1; i < n; i++) list.next[i] = i + 1;
    list.next[n] = 1;

    int curr = 1;
    int prev = n;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            prev = curr;
            curr = list.nxt(curr);
        }
        cout << curr << " ";
        list.erase_after(prev);
        curr = list.nxt(prev);
    }
}