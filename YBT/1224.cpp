#include <bits/stdc++.h>
using namespace std;

int solve(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    int maxSum = INT_MIN;

    for (int top = 0; top < N; ++top) {
        vector<int> temp(N, 0);

        for (int bottom = top; bottom < N; ++bottom) {
            for (int col = 0; col < N; ++col) {
                temp[col] += matrix[bottom][col];
            }

            int currentMax = temp[0];
            int globalMax = temp[0];
            for (int i = 1; i < N; ++i) {
                currentMax = max(temp[i], currentMax + temp[i]);
                globalMax = max(globalMax, currentMax);
            }
            maxSum = max(maxSum, globalMax);
        }
    }

    return maxSum;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << solve(matrix) << '\n';
}