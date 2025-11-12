#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    
    vector<string> spotty(N), plain(N);
    for (int i = 0; i < N; i++){
        cin >> spotty[i];
    }
    for (int i = 0; i < N; i++){
        cin >> plain[i];
    }
    
    int conv[128] = {0};
    conv['A'] = 0; 
    conv['C'] = 1; 
    conv['G'] = 2; 
    conv['T'] = 3;
    
    long long answer = 0;
    for (int i = 0; i < M - 2; i++){
        for (int j = i + 1; j < M - 1; j++){
            for (int k = j + 1; k < M; k++){
                bool seen[64] = {false};
                for (int s = 0; s < N; s++){
                    int idx = conv[spotty[s][i]] * 16 + conv[spotty[s][j]] * 4 + conv[spotty[s][k]];
                    seen[idx] = true;
                }
                bool valid = true;
                for (int p = 0; p < N; p++){
                    int idx = conv[plain[p][i]] * 16 + conv[plain[p][j]] * 4 + conv[plain[p][k]];
                    if(seen[idx]){
                        valid = false;
                        break;
                    }
                }
                if(valid)
                    answer++;
            }
        }
    }
    
    cout << answer << "\n"; 
}