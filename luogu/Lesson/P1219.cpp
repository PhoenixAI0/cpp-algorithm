#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> grid;
set<vector<int>> answers;

void dfs(int row, int location) {
    if (row == n) {answers.insert(grid); return;}
    if (find(grid.begin(), grid.end(), location) != grid.end()) return;

    for (int i = 0; i < grid.size(); i++) {
        int a = row - i; int b = location - grid[i];
        if (a == b || a == -b) return;
    }

    grid.push_back(location);
    for (int i = 1; i <= n; i++) dfs(row + 1, i);
    grid.pop_back();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) dfs(0, i);
    
    for (int x : *answers.begin()) cout << x << " ";
    cout << "\n";
    for (int x : *next(answers.begin())) cout << x << " ";
    cout << "\n";
    for (int x : *next(next(answers.begin()))) cout << x << " ";
    cout << "\n";
    cout << answers.size();
}
