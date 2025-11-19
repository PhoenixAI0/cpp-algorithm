#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binarysearch(ll target) {
    ll low = 0, high = 1000000;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if ((mid * mid * mid <= target) && ((mid + 1) * (mid + 1) * (mid + 1) > target)) return mid;
        else if (mid * mid * mid < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {ll n; cin >> n; cout << binarysearch(n) << "\n";
}}
