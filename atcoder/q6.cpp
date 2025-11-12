#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int L = 0; L <= n + 1; L++) {
        for (int R = L; R <= n + 1; R++) {
            vector<int> section(v.begin() + L, v.begin() + R);
            set<int> s(section.begin(), section.end());
            int count = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s.find(i) == s.end()) {
                    count++;
                }
            }
            ans += count;
        }
    }
    cout << ans << "\n";
}