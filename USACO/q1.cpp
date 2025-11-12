#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    static bool win[3001][3001];
    for(int i=1;i<=N;i++){
        string s; cin >> s;
        for(int j=1;j<=i;j++){
            char c = s[j-1];
            if(c=='W') win[i][j] = true;
            else if(c=='L') win[j][i] = true;
        }
    }
    vector< bitset<3001> > B(N+1);
    for(int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            if(win[i][j]) B[j].set(i);
        }
    }
    long long total = 1LL * N * N;
    while(M--){
        int s1, s2; cin >> s1 >> s2;
        bitset<3001> x = B[s1] & B[s2];
        int k = x.count();
        long long ans = total - 1LL*(N-k)*(N-k);
        cout << ans << "\n";
    }
}