#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    unordered_map<int, int> index_in_b;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        index_in_b[b[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        a[i] = index_in_b[a[i]];
    }

    int max_so_far = -1;
    int moves_needed = 0;

    for (int j = 0; j < N; ++j) {
        if (a[j] < max_so_far) {
            moves_needed++;
        } else {
            max_so_far = a[j];
        }
    }

    cout << moves_needed << endl;
}