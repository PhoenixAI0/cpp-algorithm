#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    
    while(Q--){
        string S;
        cin >> S;
        int n = S.length();
        
        if(n <3){
            cout << "-1\n";
            continue;
        }
        
        int minimal_cost = INT32_MAX;
        
        for(int i=0; i <= n-3; ++i){
            if(S[i+1] == 'O'){
                int flips =0;
                
                if(S[i] == 'O'){
                    flips +=1;
                }
                
                if(S[i+2] == 'M'){
                    flips +=1;
                }
                
                int cost = (n -3) + flips;
                
                if(cost < minimal_cost){
                    minimal_cost = cost;
                }
            }
        }
        
        if(minimal_cost != INT32_MAX){
            cout << minimal_cost << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}