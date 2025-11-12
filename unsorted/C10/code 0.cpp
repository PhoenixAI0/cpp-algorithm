#include <bits/stdc++.h>
using namespace std;

void sort2(vector<pair<int, double>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        bool flag = true;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i].second < v[j].second || (v[i].second == v[j].second && v[i].first > v[j].first)) {
                swap(v[i], v[j]);
                flag = false;
            }
        }
        if (flag) break;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, double>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort2(v);

    cout << v[m-1].first << " " << v[m-1].second << endl;
}