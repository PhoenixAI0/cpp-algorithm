#include <bits/stdc++.h>
using namespace std;

bool canReach(int k, int x) {
    if (x == k) return true;
    if (x < k) return false;
    if ((x - 1) % 2 == 0) {
        int prevVal = (x - 1) / 2;
        if (canReach(k, prevVal)) return true;
    }
    if ((x - 1) % 3 == 0) {
        int prevVal = (x - 1) / 3;
        if (canReach(k, prevVal)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    auto commaPos = line.find(',');
    int k = stoi(line.substr(0, commaPos));
    int x = stoi(line.substr(commaPos + 1));

    if (canReach(k, x)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
