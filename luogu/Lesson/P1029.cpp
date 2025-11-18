#include <bits/stdc++.h>
using namespace std;

int count(int n) {
    int ans = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans++;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans++;
    return ans;
}

int main() {
    int a, b; cin >> a >> b;
    if (b % a != 0) {
        cout << 0 << "\n"; return 0;
    }
    int c = b / a;
    cout << (1 << count(c)) << "\n";
}
