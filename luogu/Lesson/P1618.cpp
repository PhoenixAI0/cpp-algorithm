// https://www.luogu.com.cn/problem/P1618#ide
// Reflections:
// 1. Brute-force search all permutations of "123456789"
// 2. Remember to static_cast<float>(a) one of the numbers when dividing.


#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    bool flag = false;
    string s = "123456789";
    do {
        int x = stoi(s.substr(0, 3));
        int y = stoi(s.substr(3, 3));
        int z = stoi(s.substr(6, 3));
        float x1 = static_cast<float>(x) / a;
        float y1 = static_cast<float>(y) / b;
        float z1 = static_cast<float>(z) / c;
        if (x1 == y1 && y1 == z1) {
            cout << x << " " << y << " " << z << "\n";
            flag = true;
        }
    } while (next_permutation(s.begin(), s.end()));
    if (!flag) {
        cout << "No!!!" << "\n";
    }
}
