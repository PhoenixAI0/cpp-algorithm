#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c; cin >> n >> c;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> freq;
    for (int i = 0; i < n; i++) freq[a[i]]++;
    long long count = 0;
    for (int i = 0; i < n; i++) if (freq.count(a[i] - c)) count += freq[a[i] - c];
    cout << count << "\n";
}
