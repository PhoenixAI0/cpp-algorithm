#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_set<int> s;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (s.insert(x).second) v.push_back(x);
        }
        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
}
