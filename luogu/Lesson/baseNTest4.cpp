#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(double decimal) {
    if (decimal == 0.0) return "0";
    
    string result = "";
    
    bool isNegative = false;
    if (decimal < 0) {
        isNegative = true;
        decimal = abs(decimal);
    }
    
    long long integerPart = (long long)decimal;
    double fractionalPart = decimal - integerPart;
    
    if (integerPart == 0) {
        result = "0";
    } else {
        string intBinary = "";
        while (integerPart > 0) {
            intBinary = to_string(integerPart % 2) + intBinary;
            integerPart /= 2;
        }
        result = intBinary;
    }
    
    if (fractionalPart > 0) {
        result += ".";
        int precision = 20;
        while (fractionalPart > 0 && precision > 0) {
            fractionalPart *= 2;
            int bit = (int)fractionalPart;
            result += to_string(bit);
            fractionalPart -= bit;
            precision--;
        }
    }
    
    if (isNegative) {
        result = "-" + result;
    }
    
    return result;
}

double binaryToDecimal(string binary) {
    if (binary.empty()) return 0.0;
    
    bool isNegative = false;
    if (binary[0] == '-') {
        isNegative = true;
        binary = binary.substr(1);
    }
    
    double result = 0.0;
    size_t dotPos = binary.find('.');
    
    string intPart = (dotPos == string::npos) ? binary : binary.substr(0, dotPos);
    for (int i = 0; i < intPart.length(); i++) {
        if (intPart[i] == '1') {
            result += pow(2, intPart.length() - 1 - i);
        }
    }
    
    if (dotPos != string::npos && dotPos + 1 < binary.length()) {
        string fracPart = binary.substr(dotPos + 1);
        for (int i = 0; i < fracPart.length(); i++) {
            if (fracPart[i] == '1') {
                result += pow(2, -(i + 1));
            }
        }
    }
    
    if (isNegative) {
        result = -result;
    }
    
    return result;
}

int main() {
    int base; string number; cin >> base >> number;
    
    if (base == 10) {
        double decimal = stod(number);
        string binary = decimalToBinary(decimal);
        cout << binary << "\n";
    } else if (base == 2) {
        double decimal = binaryToDecimal(number);
        cout << fixed << setprecision(10) << decimal << "\n";
    }
    
    return 0;
}
