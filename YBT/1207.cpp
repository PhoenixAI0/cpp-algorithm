#include <bits/stdc++.h>
using namespace std;

int HCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n; cin >> m >> n;
    cout << HCF(m, n) << endl;
}
