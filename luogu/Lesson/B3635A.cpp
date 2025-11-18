#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cache[n+1];
    cache[0] = 0;
    for (int i = 1; i <= n; i++) {
        int a = ((i - 1 >= 0) ? cache[i - 1] + 1 : INT_MAX);
        int b = ((i - 5 >= 0) ? cache[i - 5] + 1 : INT_MAX);
        int c = ((i - 11 >= 0) ? cache[i - 11] + 1 : INT_MAX);
        cache[i] = min(a, min(b, c));
    }
    cout << cache[n];
}
