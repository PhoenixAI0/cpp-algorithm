#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowcode.in","r",stdin);
    freopen("cowcode.out","w",stdout);
    string s;
    ll n;
    cin >> s >> n;
    ll len = s.size(), cur = len;
    while(cur < n)
        cur *= 2;
    while(cur > len){
        ll half = cur / 2;
        if(n > half){
            ll pos = n - half;
            n = (pos == 1 ? half : pos - 1);
        }
        cur /= 2;
    }
    cout << s[n - 1];
}