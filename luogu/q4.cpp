#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b;
    vector<int> remaining;

    for (int i = 0; i < n; i++) {
        if (a[i] <= 15) {
            b.push_back(a[i]);
        } else {
            remaining.push_back(a[i]);
        }
    }

    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }

    for (int i = 0; i < remaining.size(); i++) {
        cout << remaining[i] << " ";
    }
    cout << endl;
}