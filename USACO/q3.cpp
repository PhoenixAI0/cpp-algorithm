#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> nxt(N+2, N+1);
    nxt[N] = N+1;
    for (int i = N-1; i >= 1; i--){
        if(s[i] == s[i+1]) nxt[i] = nxt[i+1];
        else nxt[i] = i+1;
    }
 
    vector<vector<int>> pos(26);
    for (int i = 1; i <= N; i++){
        int c = s[i]-'a';
        pos[c].push_back(i);
    }

    while(Q--){
        int l, r;
        cin >> l >> r;
        if(r - l < 2){
            cout << -1 << "\n";
            continue;
        }
        ll ans = -1;
        for (int c = 0; c < 26; c++){
            int A; 
            if((s[l]-'a') != c) A = l;
            else A = nxt[l];
            if(A >= r) continue;
            auto itB = upper_bound(pos[c].begin(), pos[c].end(), r);
            if(itB == pos[c].begin()) continue;
            int B = *prev(itB);
            if(B <= A) continue;
            int low = max(l, A+1);
            auto it = lower_bound(pos[c].begin(), pos[c].end(), low);
            if(it == pos[c].end() || *it >= B) continue;
            int mid = (A + B) / 2;
            auto itMid = lower_bound(it, pos[c].end(), mid);
            ll best = -1;
            if(itMid != pos[c].end() && *itMid < B){
                int j = *itMid;
                best = max(best, (ll)(j - A) * (B - j));
            }
            if(itMid != it){
                auto itPrev = itMid;
                itPrev--;
                if(*itPrev < B){
                    int j = *itPrev;
                    best = max(best, (ll)(j - A) * (B - j));
                }
            }
            ans = max(ans, best);
        }
        cout << ans << "\n";
    }
}