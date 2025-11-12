#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll INF = LLONG_MAX / 2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<ll> d(m), pos(m+1, 0LL), prefixPos(m+1, 0LL);
    for(int i=1; i<=m-1; i++){
        cin >> d[i];
    }

    for(int i=1; i<=m; i++){
        pos[i] = (pos[i-1] + d[i-1]);
        prefixPos[i] = prefixPos[i-1] + pos[i];
    }
    
    auto getCost = [&](int a, int b) {
        int mid = (a + b) / 2;
        ll leftCount = (mid - a + 1);
        ll sumLeft = prefixPos[mid] - prefixPos[a-1];
        ll leftPart = leftCount * pos[mid] - sumLeft;

        ll rightCount = (b - mid);
        ll sumRight = prefixPos[b] - prefixPos[mid];
        ll rightPart = sumRight - rightCount * pos[mid];

        return leftPart + rightPart;
    };

    static ll dp[501][501];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = LLONG_MAX/2; 
        }
    }
    dp[0][0] = 0;

    for (int i=1; i<=m; i++){
        for (int j=1; j<=min(i, n); j++) {
            for (int k=0; k<i; k++) {
                ll candidate = dp[k][j-1] + getCost(k+1, i);
                if (candidate < dp[i][j]) {
                    dp[i][j] = candidate;
                }
            }
        }
    }

    cout << dp[m][n] << '\n';
}