#include <bits/stdc++.h>
using namespace std;
int n;
string ans;
// ALTERNATIVE METHOD
void f(int n) {
    if (n > N) return;
    f(n+1);
    cout << n;
    f(n+1);
}

int main() {
    cin >> n;
    vector<int> ans = {1};
    for (int i = 2; i <= n; i++) {
        vector<int> newAns;
        for (int j = 0; j < ans.size(); j++) {
            if (ans[j] == (i-1)) {
                newAns.push_back(i);
                newAns.push_back(ans[j]);
                newAns.push_back(i);
            } else {
                newAns.push_back(ans[j]);
            }
        }
        ans = newAns;
    }
    for (int x : ans) cout << x;
}
