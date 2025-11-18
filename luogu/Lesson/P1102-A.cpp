#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; freq[x]++;
    }
    long long ans = 0;
    for (const auto& [a, b] : freq) {
        if (freq.find(a + c) != freq.end()) {
            ans += 1LL * b * freq[a + c];
        }
    }
    cout << ans << '\n';
}