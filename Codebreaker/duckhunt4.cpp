#include <iostream>
using namespace std;

int main() {
    int x; cin >> x;
    int a = x / 500;
    x -= a * 500;
    int b = x / 5;
    cout << a * 1000 + b * 5 << "\n";
}
