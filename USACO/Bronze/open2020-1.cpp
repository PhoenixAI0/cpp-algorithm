#include <bits/stdc++.h>
using namespace std;

// Returns size of smallest gap between any two 1s
int find_smallest_gap(string& s) {
    int smallest = INT_MAX;
    int last = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (last != -1) {
                smallest = min(smallest, i - last);
            }
            last = i;
        }
    }
    return smallest;
}

// Returns size and start position of largest gap between two 1s
pair<int,int> find_largest_gap(string& s) {
    int largest = 0, start = 0;
    int last = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (last != -1 && i - last > largest) {
                largest = i - last;
                start = last;
            }
            last = i;
        }
    }
    return {largest, start};
}

// Try placing one cow in the largest gap and return smallest gap
int try_cow_in_largest_gap(string s) {
    auto [gap, start] = find_largest_gap(s);
    if (gap >= 2) {
        s[start + gap/2] = '1';
        return find_smallest_gap(s);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0;
    string temp;
    
    // Case 1: Put both cows in largest gap
    auto [largest_gap, gap_start] = find_largest_gap(s);
    if (largest_gap >= 3) {
        temp = s;
        temp[gap_start + largest_gap/3] = '1';
        temp[gap_start + 2*largest_gap/3] = '1';
        ans = max(ans, find_smallest_gap(temp));
    }
    
    // Case 2: Put cows at both ends
    if (s[0] == '0' && s[n-1] == '0') {
        temp = s;
        temp[0] = temp[n-1] = '1';
        ans = max(ans, find_smallest_gap(temp));
    }
    
    // Case 3: Left end + largest gap
    if (s[0] == '0') {
        temp = s;
        temp[0] = '1';
        ans = max(ans, try_cow_in_largest_gap(temp));
    }
    
    // Case 4: Right end + largest gap
    if (s[n-1] == '0') {
        temp = s;
        temp[n-1] = '1';
        ans = max(ans, try_cow_in_largest_gap(temp));
    }
    
    // Case 5: Two different interior gaps
    if (largest_gap >= 2) {
        temp = s;
        temp[gap_start + largest_gap/2] = '1';
        ans = max(ans, try_cow_in_largest_gap(temp));
    }
    
    cout << ans << "\n";
    return 0;
}