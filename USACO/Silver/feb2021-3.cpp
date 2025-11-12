#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countSubmatrices(const vector<vector<int>> &mat) {
    int n = mat.size();
    vector<int> height(n, 0);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(mat[i][j] == 1)
                height[j] += 1;
            else
                height[j] = 0;
        }

        vector<ll> dp(n, 0);
        stack<int> st;
        for (int j = 0; j < n; j++) {
            while(!st.empty() && height[st.top()] >= height[j])
                st.pop();

            if(st.empty())
                dp[j] = (ll) height[j] * (j + 1);
            else
                dp[j] = (ll) height[j] * (j - st.top()) + dp[st.top()];

            st.push(j);
            total += dp[j];
        }
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> bin1(N, vector<int>(N, 0));
    vector<vector<int>> bin2(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(grid[i][j] >= 100)
                bin1[i][j] = 1;
            if(grid[i][j] > 100)
                bin2[i][j] = 1;
        }
    }

    ll count1 = countSubmatrices(bin1);
    ll count2 = countSubmatrices(bin2);

    cout << (count1 - count2) << "\n";
}