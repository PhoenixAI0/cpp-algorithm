#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> generate_moos() {
    vector<string> moos;
    moos.reserve(26 * 25);
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == j) continue;
            string s = "";
            s += (char)('a' + i);
            s += (char)('a' + j);
            s += (char)('a' + j);
            moos.push_back(s);
        }
    }
    return moos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, f;
    cin >> n >> f;
    string s;
    cin >> s;
    
    vector<string> moos = generate_moos();
    
    sort(moos.begin(), moos.end());
    int num_moos = moos.size();
    unordered_map<string, int> pattern_to_idx;
    for(int i = 0; i < num_moos; i++) {
        pattern_to_idx[moos[i]] = i;
    }
    
    vector<int> match0(num_moos, 0);
    
    vector<unordered_map<int, int>> fix_maps(num_moos);
    
    vector<unordered_map<int, int>> break_maps(num_moos);
    
    for(int i = 0; i + 2 < n; i++) {
        string window = s.substr(i, 3);
        auto it = pattern_to_idx.find(window);
        if(it != pattern_to_idx.end()){
            int p_idx = it->second;
            match0[p_idx]++;
            break_maps[p_idx][i]++;
            break_maps[p_idx][i+1]++;
            break_maps[p_idx][i+2]++;
        }
        
        for(int pos = 0; pos <3; pos++) {
            char original_char = window[pos];
            for(char c = 'a'; c <= 'z'; c++) {
                if(c == original_char) continue;
                string modified = window;
                modified[pos] = c;
                auto it_mod = pattern_to_idx.find(modified);
                if(it_mod != pattern_to_idx.end()){
                    int p_idx = it_mod->second;
                    int substitution_key = (i + pos) * 26 + (c - 'a');
                    fix_maps[p_idx][substitution_key]++;
                }
            }
        }
    }
    
    vector<string> valid_moos;
    
    for(int p_idx = 0; p_idx < num_moos; p_idx++) {
        int current_match = match0[p_idx];
        if(current_match >= f){
            valid_moos.push_back(moos[p_idx]);
            continue;
        }
        int max_total = current_match;
        for(auto &[sub_key, fix_cnt] : fix_maps[p_idx]){
            int pos = sub_key / 26;
            int c = sub_key % 26;
            int break_cnt = 0;
            auto it_break = break_maps[p_idx].find(pos);
            if(it_break != break_maps[p_idx].end()){
                break_cnt = it_break->second;
            }
            int total = current_match - break_cnt + fix_cnt;
            if(total > max_total){
                max_total = total;
            }
        }
        if(max_total >= f){
            valid_moos.push_back(moos[p_idx]);
        }
    }
    
    cout << valid_moos.size() << "\n";
    for(auto &moo : valid_moos){
        cout << moo << "\n";
    }
}