#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(5);
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    bool possible = false;
    for (int i = 0; i < 4; i++) {
        swap(v[i], v[i+1]);
        if (v == sorted) {
            cout << "Yes" << endl;
            return 0;
        }
        swap(v[i], v[i+1]);
    }
    cout << "No" << endl;
}
