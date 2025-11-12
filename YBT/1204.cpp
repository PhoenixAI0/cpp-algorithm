#include <bits/stdc++.h>
using namespace std;
//recursive function for fibonacci
int fibonacci(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    while (cin >> x) {
        cout << fibonacci(x) << endl;
    }
}
