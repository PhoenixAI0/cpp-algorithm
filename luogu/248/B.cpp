#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll n, m; cin >> n >> m;
        ll tot = n* (n-1)/2, diff = tot-m;
        ll lo=1, hi=n, max=1;
        while (lo<=hi) {
            ll mid = (lo+hi)/2;
            ll x = mid*(mid-1)/2;
            if (x<=diff) max = mid, lo = mid+1; else hi = mid-1;
        }
        ll L = 1, R = n, min = n;
        while (L<=R) {
            ll r = (L+R)/2, a = n/r, re = n%r;
            ll te;
            if (r<=1) te = 0;
            else if (r>=n) te = tot;
            else {
                ll s = re*(a+1)*(a+1)+(r-re)*a*a;
                te = (n*n-s)/2;
            }
            if (te>=diff) {
                min = r; R = r-1;
            } else L = r+1;
        }
        cout << max << ' ' << min << "\n";
    }
}
