#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first;
        t[i].second = i + 1;
    }
    sort(t.begin(), t.end());
    long long sum = 0, wait = 0;
    for (int i = 0; i < n; ++i) {
        cout << t[i].second << " ";
        if (i) wait += sum;
        sum += t[i].first;
    }
    cout << "\n";
    cout << fixed << setprecision(2) << (double)wait / n << "\n";
}
