#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> heights;
    int h;
    while (cin >> h) {
        heights.push_back(h);
    }
    
    vector<int> dp1;
    for (int h : heights) {
        auto it = upper_bound(dp1.begin(), dp1.end(), h, greater<int>());
        if (it == dp1.end()) {
            dp1.push_back(h);
        } else {
            *it = h;
        }
    }
    
    vector<int> dp2;
    for (int h : heights) {
        auto it = lower_bound(dp2.begin(), dp2.end(), h);
        if (it == dp2.end()) {
            dp2.push_back(h);
        } else {
            *it = h;
        }
    }
    
    cout << dp1.size() << endl << dp2.size() << endl;
}