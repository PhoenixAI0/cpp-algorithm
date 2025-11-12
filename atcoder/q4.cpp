#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int MAX_N = 12;

vector<unordered_set<ull>> dp;

vector<ull> subset_sum;

int N;

ull A[MAX_N];

unordered_set<ull> calc(int mask) {
    if (mask == 0) {
        return {0};
    }
    if (!dp[mask].empty()) {
        return dp[mask];
    }

    unordered_set<ull> result;

    int first = __builtin_ctz(mask);
    int submask = mask;
    while (submask) {
        if (submask & (1 << first)) {
            ull s = subset_sum[submask];
            int remaining = mask ^ submask;
            unordered_set<ull> sub_xors = calc(remaining);
            for (auto x : sub_xors) {
                result.insert(x ^ s);
            }
        }
        submask = (submask - 1) & mask;
    }

    dp[mask] = std::move(result);
    return dp[mask];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    int total_masks = 1 << N;
    subset_sum.assign(total_masks, 0);
    for(int mask = 1; mask < total_masks; ++mask){
        int last = __builtin_ctz(mask);
        int prev_mask = mask ^ (1 << last);
        subset_sum[mask] = subset_sum[prev_mask] + A[last];
    }
    
    dp.assign(total_masks, unordered_set<ull>());
    
    int full_mask = (1 << N) - 1;
    unordered_set<ull> all_xors = calc(full_mask);
    
    cout << all_xors.size() << "\n";
}