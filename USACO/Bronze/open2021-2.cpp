#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    map<string, int> members;
    vector<string> memberNames(n);
    for (int i = 0; i < n; ++i) {
        cin >> memberNames[i];
        members[memberNames[i]] = i;
    }

    vector<vector<char>> answer(n, vector<char>(n, '?'));
    for (int i = 0; i < n; ++i) {
        answer[i][i] = 'B';
    }

    for (int j = 0; j < k; ++j) {
        vector<string> publication(n);
        for (int x = 0; x < n; ++x) {
            cin >> publication[x];
        }

        for (int x = 0; x < n; ++x) {
            bool alphabetical = true;
            for (int y = x + 1; y < n; ++y) {
                if (publication[y - 1] > publication[y]) {
                    alphabetical = false;
                }
                if (!alphabetical) {
                    int a = members[publication[x]];
                    int b = members[publication[y]];
                    answer[a][b] = '0';
                    answer[b][a] = '1';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << answer[i][j];
        }
        cout << endl;
    }
}