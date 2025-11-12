#include <bits/stdc++.h>
using namespace std;

static int totalCount = 0;

void backtrack(int n, int start, int original, vector<int>& current) {
    if (n == 0) {
        cout << original << "=";
        for (int i = 0; i < (int)current.size(); i++) {
            cout << current[i];
            if (i + 1 < (int)current.size()) cout << "+";
        }
        cout << "\n";
        totalCount++;
        return;
    }

    for (int i = start; i <= n; i++) {
        if (i >= original) break;
        
        current.push_back(i);
        backtrack(n - i, i, original, current);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> current;
    backtrack(n, 1, n, current);
}
