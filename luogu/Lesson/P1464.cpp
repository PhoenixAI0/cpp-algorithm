// https://www.luogu.com.cn/problem/P1464#ide
// Reflections:
// 1. Simple recursion
// 2. Caching is all you need.

#include <bits/stdc++.h>
using namespace std;

map<tuple<long long, long long, long long>, long long> cache;

long long w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (a < b && b < c) {
        if (cache.find({a, b, c}) != cache.end()) return cache[{a, b, c}];
        long long result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        cache[{a, b, c}] = result;
        return result;
    }
    if (cache.find({a, b, c}) != cache.end()) return cache[{a, b, c}];
    long long result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    cache[{a, b, c}] = result;
    return result;
}

int main() {
   while (true) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}