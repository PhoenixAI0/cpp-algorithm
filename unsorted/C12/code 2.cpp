#include <bits/stdc++.h>
using namespace std;

vector<int> countFrequency(const vector<int>& input) {
    vector<int> buckets(101, 0);
    for (int num : input) {
        buckets[num + 50]++;
    }
    return buckets;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> buckets = countFrequency(v);
    for (int i = 0; i < 101; i++) {
        if (buckets[i] > n / 2) {
            cout << i - 50 << '\n';
            return 0;
        }
    }
    cout << "no\n";
    return 0;
}