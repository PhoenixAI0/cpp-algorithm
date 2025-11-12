#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ull;

ull readGrid(int N, istream &in) {
    ull mask = 0;
    for(int r = 0; r < N; ++r){
        string line;
        in >> line;
        for(int c = 0; c < N; ++c){
            if(line[c] == '#'){
                mask |= (1ULL << (r * N + c));
            }
        }
    }
    return mask;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    
    int N, K;
    cin >> N >> K;
    
    ull original_mask = readGrid(N, cin);
    
    vector<ull> pieces(K, 0);
    for(int i = 0; i < K; ++i){
        pieces[i] = readGrid(N, cin);
    }
    
    vector<vector<ull>> allPossibleShifts(K, vector<ull>());
    
    for(int i = 0; i < K; ++i){
        ull mask = pieces[i];
        int min_r = N, max_r = -1, min_c = N, max_c = -1;
        for(int pos = 0; pos < N*N; ++pos){
            if(mask & (1ULL << pos)){
                int r = pos / N;
                int c = pos % N;
                min_r = min(min_r, r);
                max_r = max(max_r, r);
                min_c = min(min_c, c);
                max_c = max(max_c, c);
            }
        }
        if(max_r == -1){
            continue;
        }
        int dr_min = -min_r;
        int dr_max = N - 1 - max_r;
        int dc_min = -min_c;
        int dc_max = N - 1 - max_c;
        for(int dr = dr_min; dr <= dr_max; ++dr){
            for(int dc = dc_min; dc <= dc_max; ++dc){
                ull shifted = 0;
                bool valid = true;
                for(int pos = 0; pos < N*N; ++pos){
                    if(mask & (1ULL << pos)){
                        int r = pos / N;
                        int c = pos % N;
                        int nr = r + dr;
                        int nc = c + dc;
                        if(nr < 0 || nr >= N || nc < 0 || nc >= N){
                            valid = false;
                            break;
                        }
                        int new_pos = nr * N + nc;
                        shifted |= (1ULL << new_pos);
                    }
                }
                if(valid){
                    allPossibleShifts[i].push_back(shifted);
                }
            }
        }
    }
    
    bool found = false;
    int ans_i = -1, ans_j = -1;
    for(int i = 0; i < K && !found; ++i){
        for(int j = i + 1; j < K && !found; ++j){
            for(auto &mask_i : allPossibleShifts[i]){
                for(auto &mask_j : allPossibleShifts[j]){
                    if( (mask_i & mask_j) != 0 ){
                        continue;
                    }
                    if( (mask_i | mask_j) == original_mask ){
                        ans_i = i + 1;
                        ans_j = j + 1;
                        found = true;
                        break;
                    }
                }
                if(found){
                    break;
                }
            }
        }
    }
    
    cout << ans_i << " " << ans_j << "\n";
}