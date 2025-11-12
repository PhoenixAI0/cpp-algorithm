#include <bits/stdc++.h>
using namespace std;

vector<string> rotate_stamp(const vector<string>& stamp) {
    int K = stamp.size();
    vector<string> rotated(K, string(K, '.'));
    for(int i=0;i<K;i++) {
        for(int j=0;j<K;j++) {
            rotated[j][K-1-i] = stamp[i][j];
        }
    }
    return rotated;
}

bool exact_set_cover(int M, const vector<bitset<400>>& subsets, bitset<400> &universe, vector<vector<int>> &cell_to_subsets) {
    if (universe.none()) return true;

    int min_options = INT32_MAX;
    int chosen_cell = -1;
    for(int i=0;i<M;i++) {
        if (universe[i]) {
            if (cell_to_subsets[i].size() < min_options) {
                min_options = cell_to_subsets[i].size();
                chosen_cell = i;
                if (min_options == 0) return false;
                if (min_options == 1) break;
            }
        }
    }

    if (chosen_cell == -1) return false;

    for(auto subset_idx : cell_to_subsets[chosen_cell]) {
        if ((subsets[subset_idx] & universe) == 0) continue;

        bitset<400> new_universe = universe & ~subsets[subset_idx];

        if (exact_set_cover(M, subsets, new_universe, cell_to_subsets)) {
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> target(N);
        for(int i=0;i<N;i++) {
            cin >> target[i];
        }
        int K;
        cin >> K;
        vector<string> stamp(K);
        for(int i=0;i<K;i++) {
            cin >> stamp[i];
        }

        vector<vector<string>> all_rotations;
        all_rotations.push_back(stamp);
        for(int r=1;r<4;r++) {
            all_rotations.push_back(rotate_stamp(all_rotations.back()));
        }

        map<pair<int,int>, int> cell_indices;
        int idx = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(target[i][j] == '*') {
                    cell_indices[{i,j}] = idx++;
                }
            }
        }
        int M = idx;

        if(M == 0){
            cout << "YES\n";
            continue;
        }

        vector<bitset<400>> subsets;
        vector<vector<int>> cell_to_subsets(M, vector<int>());
        for(auto &rot : all_rotations){
            int rotK = rot.size();
            for(int i=0;i <= N - rotK;i++) {
                for(int j=0;j <= N - rotK;j++) {
                    bool valid = true;
                    bitset<400> covered;
                    for(int x=0;x<rotK;x++) {
                        for(int y=0;y<rotK;y++) {
                            if(rot[x][y] == '*') {
                                int ni = i + x;
                                int nj = j + y;
                                if(target[ni][nj] != '*') {
                                    valid = false;
                                    break;
                                }
                                covered.set(cell_indices[{ni, nj}]);
                            }
                        }
                        if(!valid) break;
                    }
                    if(valid){
                        subsets.push_back(covered);
                        int current_subset_idx = subsets.size()-1;
                        for(int c=0;c<M;c++) {
                            if(covered[c]) {
                                cell_to_subsets[c].push_back(current_subset_idx);
                            }
                        }
                    }
                }
            }
        }

        bool possible = true;
        for(int c=0;c<M;c++) {
            if(cell_to_subsets[c].empty()) {
                possible = false;
                break;
            }
        }

        if(!possible){
            cout << "NO\n";
            continue;
        }

        bitset<400> universe;
        universe.reset();
        for(int c=0;c<M;c++) universe.set(c);

        bool success = exact_set_cover(M, subsets, universe, cell_to_subsets);

        if(success) cout << "YES\n";
        else cout << "NO\n";
    }
}