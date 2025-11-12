#include <bits/stdc++.h>
using namespace std;

bool isPossible(int X, int N, const vector<int>& a, const unordered_map<int, vector<int>>& recipes) {
    vector<long long> required(N + 1, 0);
    required[N] = X;

    for (int i = N; i >= 1; --i) {
        if (required[i] > a[i]) {
            if (recipes.find(i) == recipes.end()) {
                return false;
            }

            long long needed = required[i] - a[i];
            for (int constituent : recipes.at(i)) {
                required[constituent] += needed;
                if (required[constituent] > 1e9) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int K;
    cin >> K;

    unordered_map<int, vector<int>> recipes;
    for (int i = 0; i < K; ++i) {
        int L, M;
        cin >> L >> M;
        vector<int> constituents(M);
        for (int j = 0; j < M; ++j) {
            cin >> constituents[j];
        }
        recipes[L] = constituents;
    }

    if (K == 0) {
        cout << a[N] << "\n";
        return 0;
    }

    long long low = 0, high = 1e9;
    long long result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isPossible(mid, N, a, recipes)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << "\n";
}