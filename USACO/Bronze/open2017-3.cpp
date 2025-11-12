#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }
    
    map<int, vector<pair<int, int>>> color_positions;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int color = grid[i][j];
            if (color != 0) {
                color_positions[color].emplace_back(i, j);
            }
        }
    }
    
    int count = 0;
    
    for (const auto& [c, c_cells] : color_positions) {
        bool valid = true;
        
        for (const auto& [d, d_cells] : color_positions) {
            if (d == c) continue;
            if (d_cells.empty()) continue;
            
            int min_row_d = INT_MAX, max_row_d = INT_MIN;
            int min_col_d = INT_MAX, max_col_d = INT_MIN;
            
            for (const auto& [i, j] : d_cells) {
                min_row_d = min(min_row_d, i);
                max_row_d = max(max_row_d, i);
                min_col_d = min(min_col_d, j);
                max_col_d = max(max_col_d, j);
            }
            
            for (const auto& [i, j] : c_cells) {
                if (i >= min_row_d && i <= max_row_d && j >= min_col_d && j <= max_col_d) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        
        if (valid) {
            count++;
        }
    }
    
    cout << count << "\n";
}