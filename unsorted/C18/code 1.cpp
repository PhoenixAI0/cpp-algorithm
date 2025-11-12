#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> dorm(n);
    for (int i = 0; i < n; i++) {
        cin >> dorm[i];
    }

    int m;
    cin >> m;

    vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int day = 2; day <= m; day++) {
        vector<string> nextDorm = dorm;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dorm[i][j] == '@') {
                    for (auto &dir : directions) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            if (dorm[ni][nj] == '.') {
                                nextDorm[ni][nj] = '@';
                            }
                        }
                    }
                }
            }
        }
        dorm = nextDorm;
    }

    int infectedCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dorm[i][j] == '@') {
                infectedCount++;
            }
        }
    }

    cout << infectedCount << "\n";
}