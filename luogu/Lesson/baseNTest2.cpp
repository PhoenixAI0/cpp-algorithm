#include <bits/stdc++.h>
using namespace std;

int main() {
    int base; string number; cin >> base >> number;
    reverse(number.begin(), number.end());
    int result = 0;
    for (int i = 0; i < number.size(); i++) {
        result += (number[i] - '0') * pow(base, i);
    }
    cout << result << "\n";
}
