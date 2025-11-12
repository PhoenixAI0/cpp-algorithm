#include <iostream>
using namespace std;

long long factorial(int x) {
    long long result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

long long choose(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int m, n;
    cin >> m >> n;

    long long routes = choose(m + n - 2, m - 1);
    cout << routes << endl;
}