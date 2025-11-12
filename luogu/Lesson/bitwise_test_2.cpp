#include <bits/stdc++.h>
using namespace std;

string tenToBase(int base, int number) {
    if (number == 0) return "0";
    string result = "";
    while (number > 0) {
        result = to_string(number % base) + result;
        number /= base;
    }
    return result;
}

int baseToTen(int base, string number) {
    int result = 0;
    int power = 1;
    for (int i = number.size() - 1; i >= 0; i--) {
        result += (number[i] - '0') * power;
        power *= base;
    }
    return result;
}

int main() {
    string number; cin >> number;
    int num = stoi(number);
    if (num < 0) {
        num = -num;
        cout << "-" << tenToBase(2, num) << "\n";
    } else {
        cout << tenToBase(2, num) << "\n";
    }
    
    string base2number; cin >> base2number;
    bool isNegative = false;
    if (base2number[0] == '-') {
        isNegative = true;
        base2number = base2number.substr(1);
    }
    int result = baseToTen(2, base2number);
    if (isNegative) result = -result;
    cout << result << "\n";
}
