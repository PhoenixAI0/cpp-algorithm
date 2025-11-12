#include <bits/stdc++.h>
using namespace std;
vector<int> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int n; cin >> n;
    b.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<vector<int>> perms;
    for (int i = 1; i <= n; i++) {
        vector<int> curr = {i};
        int last = i;
        bool valid = true;
        
        for (int j = 0; j < n - 1; j++) {
            int next = b[j] - last;
            if (next < 1 || next > n) {
                valid = false;
                break;
            }
            curr.push_back(next);
            last = next;
        }
        
        if (valid) {
            // Check for duplicates
            vector<bool> used(n + 1);
            bool has_dup = false;
            for (int x : curr) {
                if (used[x]) {
                    has_dup = true;
                    break;
                }
                used[x] = true;
            }
            if (!has_dup) perms.push_back(curr);
        }
    }
    for (int j = 0; j < perms[0].size() - 1; j++) {
        cout << perms[0][j] << " ";
    }
    cout << perms[0][perms[0].size() - 1];
    cout << "\n";
}
