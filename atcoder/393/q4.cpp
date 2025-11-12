#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    vector<int> ones;
    for (int i = 0; i < N; i++){
        if(S[i] == '1'){
            ones.push_back(i);
        }
    }
    
    int k = ones.size();
    int mid = k / 2;  
    long long ans = 0;
    
    for (int i = 0; i < k; i++){
        int target = ones[mid] - (mid - i);
        ans += abs(ones[i] - target);
    }
    
    cout << ans << "\n";
}