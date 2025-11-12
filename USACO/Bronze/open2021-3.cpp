#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> field(n);
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
    }
    
    set<vector<pair<int, int>>> pairs;
    int answer = 0;
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'G') {
                vector<pair<int, int>> adjacent_cows;
                
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && field[ni][nj] == 'C') {
                        adjacent_cows.emplace_back(ni, nj);
                    }
                }
                
                if (adjacent_cows.size() > 2) {
                    ++answer;
                    continue;
                }
                
                if (adjacent_cows.size() == 2) {
                    sort(adjacent_cows.begin(), adjacent_cows.end());
                    pairs.insert(adjacent_cows);
                }
            }
        }
    }
    
    answer += pairs.size();
    cout << answer << "\n";
}
