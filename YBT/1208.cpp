#include <bits/stdc++.h>
using namespace std;

string powerNotation(int n) {
    if (n == 0) return "0";  
    if (n == 1) return "2";  

    string result = "";
    int power = 0;

    while (n > 0) {
        if (n % 2 == 1) { 
            if (!result.empty()) result = "+" + result; 
            if (power == 1) {
                result = "2" + result; 
            } else {
                result = "2(" + powerNotation(power) + ")" + result; 
            }
        }
        n /= 2;
        power++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << powerNotation(n) << "\n";
}
