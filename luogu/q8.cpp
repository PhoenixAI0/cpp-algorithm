#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    
    while (k--) {
        vector<long long> col_sums(m, 0);
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                col_sums[j] += grid[i][j];
            }
        }
        
        long long max_sum = *max_element(col_sums.begin(), col_sums.end());
        long long min_sum = *min_element(col_sums.begin(), col_sums.end());
        
        vector<int> target_cols;
        for(int j=0; j<m; j++){
            if(col_sums[j] == max_sum || col_sums[j] == min_sum){
                target_cols.push_back(j);
            }
        }
        
        if (target_cols.empty()) {
            continue;
        }
        
        vector<int> students;
        for(auto j : target_cols){
            for(int i=0; i<n; i++){
                students.push_back(grid[i][j]);
            }
        }
        
        sort(students.begin(), students.end(), greater<int>());
        
        vector<pair<int, int>> seat_order;
        for(int i=0; i<n; i++){
            if( (i+1) % 2 == 1 ){
                for(int j=0; j<m; j++){
                    if( find(target_cols.begin(), target_cols.end(), j) != target_cols.end() ){
                        seat_order.emplace_back(i, j);
                    }
                }
            }
            else{
                for(int j=m-1; j>=0; j--){
                    if( find(target_cols.begin(), target_cols.end(), j) != target_cols.end() ){
                        seat_order.emplace_back(i, j);
                    }
                }
            }
        }
        
        int total_seats = seat_order.size();
        int total_students = students.size();
        int assign_count = min((int)students.size(), (int)seat_order.size());
        for(int idx=0; idx<assign_count; idx++){
            int i = seat_order[idx].first;
            int j = seat_order[idx].second;
            grid[i][j] = students[idx];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << grid[i][j];
            if(j != m-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }
}