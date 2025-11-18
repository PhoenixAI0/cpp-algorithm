#include <bits/stdc++.h>
using namespace std;
int cache[1000000];

int f(int n) {
    if (n < 0) return INT_MAX - 1;
    if (n == 0) return 0;
    if (cache[n] != 0) return cache[n];
    int a = f(n - 1) + 1;
    int b = f(n - 5) + 1;
    int c = f(n - 11) + 1;
    int ans = min(a, min(b, c));
    cache[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << "\n";
}
