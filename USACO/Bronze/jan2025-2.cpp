#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> f(n+1);
    for(int i=0; i<n; i++){
        int x = a[i];
        if(!f[x]) f[x] = i+1;
    }

    vector<int> d(n+1, INT_MAX);
    vector<int> cnt(n+1);
    for(int i=n-1; i>=0; i--){
        int x = a[i];
        cnt[x]++;
        if(cnt[x] == 2 && d[x] == INT_MAX){
            d[x] = i+1;
        }
    }

    vector<int> v1, v2;
    v1.reserve(n);
    v2.reserve(n);
    for(int i=1; i<=n; i++){
        if(f[i]) v1.push_back(i);
        if(d[i] != INT_MAX) v2.push_back(i);
    }

    sort(v1.begin(), v1.end(), [&](int x, int y){
        return f[x] < f[y];
    });
    sort(v2.begin(), v2.end(), [&](int x, int y){
        return d[x] < d[y];
    });

    ll ans = 0;
    int j = 0;
    ll c = 0;

    for(int y: v2){
        int pos = d[y];
        while(j < (int)v1.size() && f[v1[j]] < pos){
            c++;
            j++;
        }
        ll pairs = c;
        if(f[y] && f[y] < pos) pairs--;
        if(pairs < 0) pairs = 0;
        ans += pairs;
    }

    cout << ans << "\n";
}
//hi :)