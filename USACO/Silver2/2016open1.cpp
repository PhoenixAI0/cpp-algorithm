#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    int x, y;
};

ll getArea(vector<Point>& cows, vector<bool>& removed) {
    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;
    
    for (int i = 0; i < cows.size(); i++) {
        if (removed[i]) continue;
        minX = min(minX, cows[i].x);
        maxX = max(maxX, cows[i].x);
        minY = min(minY, cows[i].y);
        maxY = max(maxY, cows[i].y);
    }
    
    if (minX == INT_MAX) return 0;
    return (ll)(maxX - minX) * (maxY - minY);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<Point> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    
    vector<int> candidates;
    
    vector<int> byX(n);
    iota(byX.begin(), byX.end(), 0);
    sort(byX.begin(), byX.end(), [&](int a, int b) {
        return cows[a].x < cows[b].x;
    });
    
    vector<int> byY(n);
    iota(byY.begin(), byY.end(), 0);
    sort(byY.begin(), byY.end(), [&](int a, int b) {
        return cows[a].y < cows[b].y;
    });
    
    set<int> candidateSet;
    for (int i = 0; i < min(3, n); i++) {
        candidateSet.insert(byX[i]);
        candidateSet.insert(byX[n-1-i]);
        candidateSet.insert(byY[i]);
        candidateSet.insert(byY[n-1-i]);
    }
    
    for (int idx : candidateSet) {
        candidates.push_back(idx);
    }
    
    ll minArea = LLONG_MAX;
    vector<bool> removed(n, false);
    
    int m = candidates.size();
    
    minArea = min(minArea, getArea(cows, removed));
    
    for (int i = 0; i < m; i++) {
        removed[candidates[i]] = true;
        minArea = min(minArea, getArea(cows, removed));
        removed[candidates[i]] = false;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            removed[candidates[i]] = removed[candidates[j]] = true;
            minArea = min(minArea, getArea(cows, removed));
            removed[candidates[i]] = removed[candidates[j]] = false;
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                removed[candidates[i]] = removed[candidates[j]] = removed[candidates[k]] = true;
                minArea = min(minArea, getArea(cows, removed));
                removed[candidates[i]] = removed[candidates[j]] = removed[candidates[k]] = false;
            }
        }
    }
    
    cout << minArea << "\n";
}
