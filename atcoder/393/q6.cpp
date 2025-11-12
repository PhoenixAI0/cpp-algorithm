#include <bits/stdc++.h>
using namespace std;
 
struct Fenw {
    int n;
    vector<int> fenw;
    Fenw(int n) : n(n), fenw(n+1, 0) { }
    void update(int i, int val) {
        for(; i <= n; i += i & -i)
            fenw[i] = max(fenw[i], val);
    }
    int query(int i) {
        int res = 0;
        for(; i; i -= i & -i)
            res = max(res, fenw[i]);
        return res;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    
    vector<int> compArr = A;
    sort(compArr.begin(), compArr.end());
    compArr.erase(unique(compArr.begin(), compArr.end()), compArr.end());
    auto getComp = [&](int x) {
        return int(lower_bound(compArr.begin(), compArr.end(), x) - compArr.begin()) + 1;
    };
    int M = compArr.size();
    
    vector<int> dp(N, 0);
    Fenw fenw1(M);
    for (int i=0; i<N; i++){
        int pos = getComp(A[i]);
        int best = fenw1.query(pos - 1);
        dp[i] = best + 1;
        fenw1.update(pos, dp[i]);
    }
    
    struct Query {
        int R, X, idx;
    };
    vector<Query> queries(Q);
    for (int i=0; i<Q; i++){
        int R, X;
        cin >> R >> X;
        queries[i] = {R, X, i};
    }
    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b){
        return a.R < b.R;
    });
    
    Fenw fenw2(M);
    vector<int> ans(Q, 0);
    int curr = 0;
    for (auto &q : queries){
        while (curr < q.R) {
            int pos = getComp(A[curr]);
            fenw2.update(pos, dp[curr]);
            curr++;
        }
        int pos = upper_bound(compArr.begin(), compArr.end(), q.X) - compArr.begin();
        int res = (pos > 0 ? fenw2.query(pos) : 0);
        ans[q.idx] = res;
    }
    
    for (int i=0; i<Q; i++){
        cout << ans[i] << "\n";
    }
}