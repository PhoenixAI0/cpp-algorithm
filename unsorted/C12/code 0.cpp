#include <bits/stdc++.h>
using namespace std;

vector<int> sort4(vector<int>& input) {
    vector<int> buckets(1001, 0);
    for (int i = 0; i < input.size(); i++) {
        buckets[input[i]]++;
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
    int count = 0;
    vector<int> buckets = sort4(v);
    for (int i = 0; i < 1001; i++) {
        if (buckets[i] > 0) {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < 1001; i++) {
        if (buckets[i] > 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}