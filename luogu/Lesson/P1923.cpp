#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n - 1, k = n - m + 1;
    while (true) {
        if (l == r) break;
        int pivot = a[l + rand() % (r - l + 1)];
        int i = l, j = r;
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) swap(a[i++], a[j--]);
        }
        if (m <= j) {
            r = j;
        } else if (m >= i) {
            l = i;
        } else {
            l = j + 1;
            break;
        }
    }
    cout << a[l] << "\n";
}
