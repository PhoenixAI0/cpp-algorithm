#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> number = {0};
    while (true) {
        number[0]++;
        int i = 0;
        while (i < number.size() && number[i] == n) {
            number[i] = 0;
            if (i == number.size() - 1) {
                number.push_back(1);
                break;
            } else {
                number[i + 1]++;
            }
            ++i;
        }
        for (int j = number.size() - 1; j >= 0; j--) {
            cout << number[j];
        }
        cout << "\n";
    }
}
