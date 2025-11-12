#include <bits/stdc++.h>
using namespace std;

vector<int> sort(vector<int> a) {
    sort(a.begin(), a.end());
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = sort(a);
    b.erase(remove_if(b.begin(), b.end(), [](int x) { return x % 2 == 0; }), b.end());
    if (!b.empty()) {
        for (size_t i = 0; i < b.size() - 1; i++) {
            cout << b[i] << ",";
        }
        cout << b.back() << endl;
    } else {
        cout << endl;
    }
}
