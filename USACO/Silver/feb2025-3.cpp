#include <bits/stdc++.h>
using namespace std;

long long mygcd(long long x, long long y) {
    while (y != 0) {
        long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long a,b,c,d;
        cin >> a >> b >> c >> d;

        if(mygcd(a,b) != mygcd(c,d) || a>c || b>d){
            cout << -1 << "\n";
            continue;
        }

        if(a == c && b == d){
            cout << 0 << "\n";
            continue;
        }

        long long ans = 0;
        while(true){
            if(c == a && d == b) {
                cout << ans << "\n";
                break;
            }
            if(c < a || d < b){
                cout << -1 << "\n";
                break;
            }
            if(c > d){
                long long q = (c - a) / d;
                if(q == 0){
                    cout << -1 << "\n";
                    break;
                }
                c -= q*d;
                ans += q;
            }
            else if(d > c){
                long long q = (d - b) / c;
                if(q == 0){
                    cout << -1 << "\n";
                    break;
                }
                d -= q*c;
                ans += q;
            }
            else {
                cout << -1 << "\n";
                break;
            }
        }
    }
}