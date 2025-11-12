// https://atcoder.jp/contests/abc430/tasks/abc430_d
// O(n log n) solution
// Reflections: 
// 1. We should use a map to store the data rather than using a set of pairs to allow for easier manipulation of the data. (Sets do not allow for editing of elements.)
// 2. Remember to use long long for the distance sum.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> s; s[0] = 0;
    long long d = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s[x] = 0;
        auto it = s.find(x);
        long long dist = 0;
        auto it_prev = it, it_next = it;
        bool has_prev = false, has_next = false;

        if (it != s.begin()) {
            --it_prev; has_prev = true;
        }
        ++it_next;
        if (it_next != s.end()) {
            has_next = true;
        }

        if (has_prev && has_next) {
            dist = min(abs(it->first - it_prev->first), abs(it->first - it_next->first));
        } else if (has_prev) {
            dist = abs(it->first - it_prev->first);
        } else if (has_next) {
            dist = abs(it->first - it_next->first);
        }
        s[x] = dist;

        d += dist;

        if (has_prev && (it_prev->second > abs(it_prev->first - x) || it_prev->second == 0)) {
            d -= it_prev->second;
            d += abs(it_prev->first - x);
            s[it_prev->first] = abs(it_prev->first - x);
        }
        if (has_next && (it_next->second > abs(it_next->first - x) || it_next->second == 0)) {
            d -= it_next->second;
            d += abs(it_next->first - x);
            s[it_next->first] = abs(it_next->first - x);
        }

        cout << d << "\n";
    }
}