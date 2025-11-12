#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    
    int N;
    cin >> N;
    vector<pair<int,int>> cows(N);
    vector<int> candX, candY;
    
    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
        candX.push_back(x + 1);
        candY.push_back(y + 1);
    }
    
    sort(candX.begin(), candX.end());
    candX.erase(unique(candX.begin(), candX.end()), candX.end());
    sort(candY.begin(), candY.end());
    candY.erase(unique(candY.begin(), candY.end()), candY.end());
    
    int ans = INT_MAX;
    for (int a : candX){
        for (int b : candY){
            int topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
            for (auto cow : cows){
                if(cow.first < a && cow.second > b)
                    topLeft++;
                else if(cow.first > a && cow.second > b)
                    topRight++;
                else if(cow.first < a && cow.second < b)
                    bottomLeft++;
                else if(cow.first > a && cow.second < b)
                    bottomRight++;
            }
            int M = max({topLeft, topRight, bottomLeft, bottomRight});
            ans = min(ans, M);
        }
    }
    cout << ans << "\n";
}
