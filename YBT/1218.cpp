#include <bits/stdc++.h>
using namespace std;

bool canWin(int a, int b) {
    if (a < b) swap(a, b);
    bool firstPlayerTurn = true;

    while (b > 0) {
        if (a / b >= 2) return firstPlayerTurn;
        int temp = a % b;
        a = b;
        b = temp;
        firstPlayerTurn = !firstPlayerTurn;
    }
    return !firstPlayerTurn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        
        if (canWin(a, b)) {
            cout << "win\n";
        } else {
            cout << "lose\n";
        }
    }
}