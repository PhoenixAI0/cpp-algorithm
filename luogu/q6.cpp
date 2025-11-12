#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    
    vector<long long> col_sums(m, 0);
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            col_sums[j] += a[i][j];
        }
    }
    
    long long max_sum;
    int winning_col;
    for(int j=0; j<m; j++){
        if(col_sums[j] > max_sum){
            max_sum = col_sums[j];
            winning_col = j;
        }
        else if(col_sums[j] == max_sum){
            winning_col = j;
        }
    }
    
    int max_level;
    for(int i=0; i<n; i++){
        if(a[i][winning_col] > max_level){
            max_level = a[i][winning_col];
        }
    }
    
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i][winning_col] == max_level){
            count++;
        }
    }
    
    cout << max_level << " " << count << "\n";
}