#include <bits/stdc++.h>
using namespace std;

bool is_feasible(int p, int N, int M, int K, const vector<int> &hierarchy, const vector<pair<int, int>> &fixed_constraints) {
    vector<int> order(N+1, 0);
    vector<int> fixed_pos(N+1, 0);
    for(auto &fc : fixed_constraints){
        int cow = fc.first;
        int pos = fc.second;
        fixed_pos[cow] = pos;
    }

    if(fixed_pos[1] != 0){
        if(p != fixed_pos[1]){
            return false;
        }
    }
    if(order[p] != 0 && order[p] !=1 ){
        return false;
    }
    order[p] = 1;

    for(int cow=1; cow<=N; cow++){
        if(cow ==1){
            continue;
        }
        if(fixed_pos[cow] !=0){
            int pos = fixed_pos[cow];
            if(pos == p && cow !=1){
                return false;
            }
            if(order[pos] !=0 && order[pos] != cow){
                return false;
            }
            order[pos] = cow;
        }
    }

    int last_pos =0;
    for(auto &cow : hierarchy){
        if(fixed_pos[cow] !=0){
            int pos = fixed_pos[cow];
            if(pos <= last_pos){
                return false;
            }
            last_pos = pos;
            continue;
        }
        int assigned_pos = -1;
        for(int pos=1; pos<=N; pos++){
            if(order[pos] == cow){
                assigned_pos = pos;
                break;
            }
        }
        if(assigned_pos != -1){
            if(assigned_pos <= last_pos){
                return false;
            }
            last_pos = assigned_pos;
            continue;
        }
        int assign_pos = -1;
        for(int pos=last_pos+1; pos<=N; pos++){
            if(order[pos] ==0){
                assign_pos = pos;
                break;
            }
        }
        if(assign_pos == -1){
            return false;
        }
        order[assign_pos] = cow;
        last_pos = assign_pos;
    }

    for(int cow=1; cow<=N; cow++){
        bool assigned = false;
        for(int pos=1; pos<=N; pos++){
            if(order[pos] == cow){
                assigned = true;
                break;
            }
        }
        if(assigned){
            continue;
        }
        int assign_pos = -1;
        for(int pos=1; pos<=N; pos++){
            if(order[pos] ==0){
                assign_pos = pos;
                break;
            }
        }
        if(assign_pos == -1){
            return false;
        }
        order[assign_pos] = cow;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> hierarchy(M);
    for(int i=0; i<M; i++) cin >> hierarchy[i];
    
    vector<pair<int, int>> fixed_constraints(K);
    for(int i=0; i<K; i++) cin >> fixed_constraints[i].first >> fixed_constraints[i].second;
    
    int cow1_fixed_pos =0;
    for(auto &fc : fixed_constraints){
        if(fc.first ==1){
            cow1_fixed_pos = fc.second;
            break;
        }
    }
    
    for(int p=1; p<=N; p++){
        if(cow1_fixed_pos !=0 && p != cow1_fixed_pos){
            continue;
        }
        bool conflict = false;
        for(auto &fc : fixed_constraints){
            if(fc.second == p && fc.first !=1){
                conflict = true;
                break;
            }
        }
        if(conflict && cow1_fixed_pos ==0){
            continue;
        }
        if(is_feasible(p, N, M, K, hierarchy, fixed_constraints)){
            cout << p;
            return 0;
        }
    }
}