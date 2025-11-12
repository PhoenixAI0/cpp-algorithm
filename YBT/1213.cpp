#include <bits/stdc++.h>
using namespace std;
int countPermutations;

bool check(vector<int> &board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(vector<int> &board, int row, int n, vector<string> &solutions) {
    if (row == n) {
        string solution;
        for (int i = 0; i < n; i++) {
            solution += to_string(board[i]);
        }
        solutions.push_back(solution);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (check(board, row, col)) {
            board[row] = col;
            solve(board, row + 1, n, solutions);
        }
    }
}

int main() {
    int n = 8;
    vector<int> board(n);
    vector<string> solutions;

    solve(board, 0, n, solutions);

    sort(solutions.begin(), solutions.end(), [](const string &a, const string &b) {
        return stoi(a) < stoi(b);
    });

    for (const auto &solution : solutions) {
        countPermutations++;
        cout << "No. " << countPermutations << "\n";
        for (char c : solution) {
            for (int i = 0; i < n; i++) {
                cout << (i == c - '0' ? "1 " : "0 ");
            }
            cout << '\n';
        }
    }
}
