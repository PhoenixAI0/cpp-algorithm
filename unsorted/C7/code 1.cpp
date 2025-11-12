#include <bits/stdc++.h>
using namespace std;

int main() {
    string c;
    cin >> c;
    
    int length = (int)c.length();
    int orig[1002];
    memset(orig, 0, sizeof(orig));
    
    for (int i = 1; i <= length; i++) {
        if (isdigit(c[i - 1])) {
            orig[i] = c[i - 1] - '0';
        } else {
            cerr << "Invalid input: non-digit character found." << endl;
            return 1;
        }
    }

    int num[1002];
    memcpy(num, orig, sizeof(orig));
       
    int carry = 0;
    for (int j = 1; j <= length; j++) {
        int tmp = carry * 10 + num[j];
        num[j] = tmp / 13;
        carry = tmp % 13;
    }
    int x = 0;
    while (num[x] == 0 && x < length) {
        x++;
    }
    for (int j = x; j <= length; j++) {
        cout << num[j];
    }
    cout << "\n" << carry << endl;
}