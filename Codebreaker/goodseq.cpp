#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    int ans = 0;
    for (auto x : freq) {
        if (x.second >= x.first) ans += x.second - x.first;
        else ans += x.second;
    }
    cout << ans;
}
