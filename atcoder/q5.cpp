#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> group[4]; 
    
    ll sumA[4] = {0, 0, 0, 0};
    
    for(int i=0; i<N; ++i){
        int V, A, C;
        cin >> V >> A >> C;
        if(V >=1 && V <=3){
            group[V].emplace_back(A, C);
            sumA[V] += A;
        }
        
    }
    
    auto compute_dp = [&](const vector<pair<int,int>> &items) -> vector<int>{
        vector<int> dp(X+1, 0);
        for(auto &[A, C] : items){
            if(C > X) continue; 
            for(int c = X; c >= C; --c){
                if(dp[c - C] + A > dp[c]){
                    dp[c] = dp[c - C] + A;
                }
            }
        }
        return dp;
    };
    
    vector<int> dp1, dp2, dp3;
    dp1 = compute_dp(group[1]);
    dp2 = compute_dp(group[2]);
    dp3 = compute_dp(group[3]);
    
    ll upper = min({sumA[1], sumA[2], sumA[3]});
    
    ll low = 0;
    ll high = upper;
    ll result = 0;
    
    while(low <= high){
        ll mid = low + (high - low) / 2;
        
        auto find_min_c = [&](const vector<int> &dp, ll M) -> ll{
            for(int c=0; c<=X; ++c){
                if(dp[c] >= M){
                    return c;
                }
            }
            return X+1; 
        };
        
        ll c1 = find_min_c(dp1, mid);
        ll c2 = find_min_c(dp2, mid);
        ll c3 = find_min_c(dp3, mid);
        
        if(c1 <= X && c2 <= X && c3 <= X && (c1 + c2 + c3) <= X){
            result = mid;
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    
    cout << result;
}