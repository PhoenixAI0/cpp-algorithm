#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> preference;
vector<int> answer;
vector<bool> used; // Tracks if a choice is assigned
int num = 0;

void search(vector<vector<bool>> &preference, int student = 0) {
    int n = preference.size(), m = preference[0].size();
    if (student == n) {
        for (int i = 0; i < m; i++) {
            cout << answer[i] + 1 << " ";
        }
        cout << "\n";
        num++;
        return;
    }
    for (int i = 0; i < m; i++) {
        if (preference[student][i] && !used[i]) { // Only proceed if choice is available
            used[i] = true;
            answer[i] = student;
            search(preference, student + 1);
            used[i] = false; // Backtrack: mark the choice as available
            answer[i] = -1;  // Reset assignment after backtracking
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    preference.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            preference[i][j] = x == 1;
        }
    }
    answer.resize(m, -1);
    used.resize(m, false); // Initialize the used vector
    search(preference);
    cout << num << "\n";
}