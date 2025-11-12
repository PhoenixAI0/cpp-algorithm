#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    //get index of largest x
    int largest_x = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first > v[largest_x].first) {
            largest_x = i;
        }
    }
    //get index of smallest x
    int smallest_x = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first < v[smallest_x].first) {
            smallest_x = i;
        }
    }
    //get index of largest y
    int largest_y = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second > v[largest_y].second) {
            largest_y = i;
        }
    }
    //get index of smallest y
    int smallest_y = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second < v[smallest_y].second) {
            smallest_y = i;
        }
    }
    
    long long min_area = LLONG_MAX;
    vector<int> remove_candidates = {largest_x, smallest_x, largest_y, smallest_y};
    
    // Try removing each candidate point
    for (int idx : remove_candidates) {
        int min_x = INT_MAX, max_x = INT_MIN;
        int min_y = INT_MAX, max_y = INT_MIN;
        
        // Calculate area without the removed point
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            min_x = min(min_x, v[i].first);
            max_x = max(max_x, v[i].first);
            min_y = min(min_y, v[i].second);
            max_y = max(max_y, v[i].second);
        }
        
        long long area = 1LL * (max_x - min_x) * (max_y - min_y);
        min_area = min(min_area, area);
    }
    
    cout << min_area << "\n";
}