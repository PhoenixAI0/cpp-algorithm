#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(n, 0);
    vector<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.back()] <= a[i]) s.pop_back();
        if (!s.empty()) ans[i] = s.back() + 1;
        s.push_back(i);
    }
    for (int x : ans) cout << x << " ";
}
