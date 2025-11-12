#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) 
            return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0, lastCovered = -1;
    for (const auto& interval : intervals) {
        if (interval.first > lastCovered) {
            count++;
            lastCovered = interval.second;
        }
    }
    
    cout << count << '\n';
}