#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    map<int, int> next;

    void insert(int x, int y) {
        if (next.find(x) != next.end()) next[y] = next[x];
        next[x] = y;
    }

    int nxt(int x) {
        return (next.find(x) != next.end() ? next[x] : 0);
    }

    void erase(int x) {
        int y = next[x];
        next[x] = next[y];
        next.erase(y);
    }
};
