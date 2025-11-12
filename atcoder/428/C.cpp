#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; 
    cin >> q;

    vector<int> bal_hist;
    vector<int> mn_hist;

    while (q--) {
        int type; 
        cin >> type;

        if (type == 1) {
            char c; cin >> c;
            int d = (c == '(' ? 1 : -1);

            int prev_bal = bal_hist.empty() ? 0 : bal_hist.back();
            int prev_mn  = mn_hist.empty()  ? 0 : mn_hist.back();

            int cur_bal = prev_bal + d;
            int cur_mn  = min(prev_mn, cur_bal);

            bal_hist.push_back(cur_bal);
            mn_hist.push_back(cur_mn);
        } else {
            if (!bal_hist.empty()) { 
                bal_hist.pop_back();
                mn_hist.pop_back();
            }
        }

        int bal = bal_hist.empty() ? 0 : bal_hist.back();
        int mn  = mn_hist.empty()  ? 0 : mn_hist.back();

        cout << ((bal == 0 && mn >= 0) ? "Yes" : "No") << '\n';
    }
}