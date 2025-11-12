#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int numerator = 0, denominator = 1;

    for (int i = 0; i < n; ++i) {
        string fraction;
        cin >> fraction;

        size_t slashPos = fraction.find('/');
        int p = stoi(fraction.substr(0, slashPos));
        int q = stoi(fraction.substr(slashPos + 1));

        numerator = numerator * q + p * denominator;
        denominator *= q;

        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

    if (denominator == 1) {
        cout << numerator << "\n"; 
    } else {
        cout << numerator << "/" << denominator << "\n"; 
    }
}
