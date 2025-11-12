#include <bits/stdc++.h>
using namespace std;

static map<string, int> a = {
    {"Ocelot", 0},
    {"Serval", 1},
    {"Lynx", 2}
};

int main() {
    string x, y; cin >> x >> y;
    cout << (a[x] >= a[y] ? "Yes" : "No");
}
