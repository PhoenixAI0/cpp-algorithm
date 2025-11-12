#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool isNegative = (x < 0);
        x = abs(x);
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long long ans = stoll(s);
        return ans < INT_MIN || ans > INT_MAX ? 0 : (isNegative ? -ans : ans);
    }
};