#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const vector<int>& num, int len) {
    for (int i = 0; i < len / 2; ++i) {
        if (num[i] != num[len - 1 - i]) return false;
    }
    return true;
}

int main() {
    int base;
    string s;
    cin >> base >> s;
    vector<int> num;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        int d;
        if (isdigit(s[i])) {
            d = s[i] - '0';
        } else if (isalpha(s[i])) {
            d = toupper(s[i]) - 'A' + 10;
        } else {
            cerr << "Invalid character in input" << endl;
            return 1;
        }
        if (d >= base) {
            cerr << "Digit out of range for given base" << endl;
            return 1;
        }
        num.push_back(d);
    }

    int len = (int)num.size();
    if (isPalindrome(num, len)) {
        cout << 0 << endl;
        return 0;
    }

    int iterations = 0;
    while (!isPalindrome(num, len) && iterations < 30) {
        vector<int> rev(num.begin(), num.begin() + len);
        reverse(rev.begin(), rev.end());

        int carry = 0;
        for (int i = 0; i < len || carry; ++i) {
            if (i == len) {
                num.push_back(0);
                ++len;
            }
            int sum = num[i] + rev[i] + carry;
            num[i] = sum % base;
            carry = sum / base;
        }

        while (len > 1 && num[len - 1] == 0) {
            --len;
        }

        ++iterations;
    }

    if (iterations == 30) {
        cout << "impossible" << endl;
    } else {
        cout << iterations << endl;
    }
}