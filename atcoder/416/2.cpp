#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; 
    cin >> S;
    string T = S;
    bool used = false;
    for (size_t i = 0; i < S.size(); ++i) {
        if (S[i] == '#') {
            T[i] = '#';
            used = false;
        } else {
            if (!used) {
                T[i] = 'o';
                used = true;
            } else {
                T[i] = '.';
            }
        }
    }
    cout << T << '\n';
}