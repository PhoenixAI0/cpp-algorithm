#include <bits/stdc++.h>
using namespace std;

int main() {
    int base, number; cin >> base >> number;
    string result = "";
    while (number > 0) {
        result = to_string(number % base) + result;
        number /= base;
    }
    cout << result << "\n";
}
