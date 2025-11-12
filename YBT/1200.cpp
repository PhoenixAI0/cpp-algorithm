#include <bits/stdc++.h>
using namespace std;
unordered_map<string, long long> memo;

long long countFactorizations(int a, int start) {
    ostringstream oss;
    oss << a << '#' << start;
    string key = oss.str();
    
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }   
    long long ways = 0;

    if (a >= start) {
        ways += 1;  
    }

    int limit = (int) floor(sqrt(a));
    for (int factor = start; factor <= limit; ++factor) {
        if (a % factor == 0) {
            int remainder = a / factor;
            
            if (remainder >= factor) {
                ways += countFactorizations(remainder, factor);
            }
        }
    }
    memo[key] = ways;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  
    cin >> n;

    while(n--) {
        int a;
        cin >> a;        
        long long result = countFactorizations(a, 2);
        cout << result << "\n";
    }
}
