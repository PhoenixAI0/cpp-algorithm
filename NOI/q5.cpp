#include <bits/stdc++.h>
using namespace std;

struct Pre {
    int prev_i, prev_j, prev_mode; 
    char op; 
    bool valid;
    int pos; 
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++){
        cin >> b[j];
    }
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());

    vector<long long> dpE(n+1, numeric_limits<long long>::max());
    vector<Pre> preE(n+1, {0,0,0,' ',false,0});
    dpE[0] = 0; 

    vector<vector<long long>> dpP(n+1, vector<long long>(n+1, numeric_limits<long long>::max()));
    vector<vector<Pre>> preP(n+1, vector<Pre>(n+1, {0,0,0,' ',false,0}));

    vector<vector<long long>> dpO(n+1, vector<long long>(n+1, numeric_limits<long long>::max()));
    vector<vector<Pre>> preO(n+1, vector<Pre>(n+1, {0,0,0,' ',false,0}));

    for (int i = 0; i <= n; i++){
        if (dpE[i] != numeric_limits<long long>::max() && i < n) {
            int new_i = i+1, new_j = i; 
            long long new_cost = dpE[i]; 
            if(new_cost < dpP[new_i][new_j]){
                dpP[new_i][new_j] = new_cost;
                preP[new_i][new_j] = {i, i, 0, 'P', true, a[new_i]};
            }
        }

        if(i >= 1) {
            for (int j = 0; j < i; j++){
                if(dpP[i][j] == numeric_limits<long long>::max()) continue;
                long long cur_cost = dpP[i][j];
                int load = i - j; 
                int curPos = a[i]; 
                if(i < n && load < c) {
                    int new_i = i+1, new_j = j;
                    long long costAdd = abs(a[new_i] - curPos);
                    long long tot = cur_cost + costAdd;
                    if(tot < dpP[new_i][new_j]){
                        dpP[new_i][new_j] = tot;
                        preP[new_i][new_j] = {i, j, 1, 'P', true, a[new_i]};
                    }
                }
                if(j < n) {
                    int new_j = j+1;
                    long long costAdd = abs(b[new_j] - curPos);
                    long long tot = cur_cost + costAdd;
                    if(i == new_j){
                        if(tot < dpE[i]){
                            dpE[i] = tot;
                            preE[i] = {i, j, 1, 'O', true, b[new_j]};
                        }
                    } else { 
                        if(tot < dpO[i][new_j]){
                            dpO[i][new_j] = tot;
                            preO[i][new_j] = {i, j, 1, 'O', true, b[new_j]};
                        }
                    }
                }
            }

            for (int j = 1; j < i; j++){
                if(dpO[i][j] == numeric_limits<long long>::max()) continue;
                long long cur_cost = dpO[i][j];
                int load = i - j; 
                int curPos = b[j]; 
                if(i < n && load < c) {
                    int new_i = i+1, new_j = j;
                    long long costAdd = abs(a[new_i] - curPos);
                    long long tot = cur_cost + costAdd;
                    if(tot < dpP[new_i][new_j]){
                        dpP[new_i][new_j] = tot;
                        preP[new_i][new_j] = {i, j, 2, 'P', true, a[new_i]};
                    }
                }
                if(j < n) {
                    int new_j = j+1;
                    long long costAdd = abs(b[new_j] - curPos);
                    long long tot = cur_cost + costAdd;
                    if(i == new_j){
                        if(tot < dpE[i]){
                            dpE[i] = tot;
                            preE[i] = {i, j, 2, 'O', true, b[new_j]};
                        }
                    } else {
                        if(tot < dpO[i][new_j]){
                            dpO[i][new_j] = tot;
                            preO[i][new_j] = {i, j, 2, 'O', true, b[new_j]};
                        }
                    }
                }
            }
        }
    }

    long long ans = dpE[n];
    cout << ans << "\n";

    vector<int> seq;
    int cur_i = n, cur_j = n, cur_mode = 0; 
    while(!(cur_i == 0 && cur_j == 0 && cur_mode == 0)){
        Pre pre;
        if(cur_mode == 0) {
            pre = preE[cur_i];
        } else if(cur_mode == 1) {
            pre = preP[cur_i][cur_j];
        } else { 
            pre = preO[cur_i][cur_j];
        }
        if(!pre.valid) break; 
        seq.push_back(pre.pos);
        cur_i = pre.prev_i;
        cur_j = pre.prev_j;
        cur_mode = pre.prev_mode;
    }
    reverse(seq.begin(), seq.end());

    for (int i = 0; i < (int)seq.size(); i++){
        cout << seq[i] << (i+1 == seq.size() ? "\n" : " ");
    }
}