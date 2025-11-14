#include <bits/stdc++.h>
using namespace std;

int check(int x) {
    int ans = 0, remain = 0;
    while (x > 0) {
        ans += x;
        x += remain;
        remain = x % 3;
        x /= 3;
    }
    return ans;
}

int binarysearch(int target) {
    int low = 0, high = target;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int checkMid = check(mid);
        int checkMidMinus1 = (mid > 0) ? check(mid - 1) : 0;
        
        if (checkMid >= target && checkMidMinus1 < target) return mid;
        else if (checkMid < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n; cin >> n;
    cout << binarysearch(n);
}
