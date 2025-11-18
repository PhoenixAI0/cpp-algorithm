#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> freq;
    int n, m; cin >> n >> m;
    int k; cin >> k; 
    while (k--) {
        int a, b; cin >> a >> b;
        freq[a]++;
        if (freq[a] == m) cout << a << " ";
    }
}
