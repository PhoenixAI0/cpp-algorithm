#include <bits/stdc++.h>
using namespace std;

bool isDominated(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first && a.second <= b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    vector<bool> remove(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isDominated(v[i], v[j]) && !isDominated(v[j], v[i])) {
                remove[i] = true;
                break;
            }
        }
    }
    
    vector<pair<int, int>> result;
    for (int i = 0; i < n; i++) {
        if (!remove[i]) result.push_back(v[i]);
    }
    
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << "(" << result[i].first << "," << result[i].second << ")";
        if (i < result.size() - 1) cout << ",";
    }
    cout << endl;
}