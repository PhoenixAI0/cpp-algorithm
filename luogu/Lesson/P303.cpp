#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a == "0" || b == "0") {
        cout << 0 << endl;
        return 0;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> result(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            result[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = 0; i < result.size(); i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] != 0) {
            for (int j = i; j >= 0; j--) {
                cout << result[j];
            }
            break;
        }
    }
}
