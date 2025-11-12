#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N + 1);
    A[0] = 1;
    for (int i = 1; i <= N; ++i) {
        long long sum = 0;
        for (int j = 0; j < i; ++j) {
            int x = A[j];
            int res = 0;
            while (x) {
                res += x % 10;
                x /= 10;
            }
            sum += res;
        }
        A[i] = sum;
    }
    cout << A[N] << '\n';
}
