#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    int n; cin >> n;
    vector<pair<int, string>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        a[i].first = i + 1;
    }
    string maxVal = a[0].second;
    for (int i = 1; i < n; i++) {
        if (cmp(maxVal, a[i].second)) {
            maxVal = a[i].second;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i].second == maxVal) {
            cout << a[i].first << "\n" << a[i].second << "\n";
        }
    }
}
