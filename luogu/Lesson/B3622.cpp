#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> ans;

void dfs(int depth) {
    if (depth > n) {
        for (char c : ans) cout << c;
        cout << "\n";
        return;
    }
    ans.push_back('N');
    dfs(depth + 1);
    ans.pop_back();
    ans.push_back('Y');
    dfs(depth + 1);
    ans.pop_back();
}

int main() {
    cin >> n;
    dfs(1);
}
