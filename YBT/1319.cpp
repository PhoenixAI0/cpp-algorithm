#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> v;

int findIndex(vector<int>& v, int val) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == val) {
            return i;
        }
    }
    return -1;
}

void getAvg(vector<int>& v, int n, int idx = 0) {
    if (idx == n) {
        return;
    }
    getAvg(v, n, idx + 1);
    for (int i = 0; i < idx; i++) ans += v[i];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) {
        cout << findIndex(v, sorted[i]) + 1 << " ";
    }
    cout << "\n";
    getAvg(sorted, n);
    float avg = static_cast<float>(ans) / n;
    cout << fixed << setprecision(2) << avg << "\n";
}
