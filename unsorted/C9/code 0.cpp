#include <bits/stdc++.h>
using namespace std;

void sort2(vector<pair<string, int>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i].second < v[j].second || (v[i].second == v[j].second && v[i].first > v[j].first)) {
                swap(v[i], v[j]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort2(v);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}