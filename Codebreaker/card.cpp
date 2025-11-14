#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, k;
    string moves;
    
    cin >> m >> k >> moves;
    
    deque<int> a;
    for (int i = 0; i < m; i++) a.push_back(i);
    
    for (char move : moves) {
        if (move == '.') break;
        
        if (move == 'A') {
            int top = a.front();
            a.pop_front();
            a.push_back(top);
        } else if (move == 'B') {
            int second = a[1];
            a.erase(a.begin() + 1);
            a.push_back(second);
        }
    }
    
    cout << a[k-1] << " " << a[k] << " " << a[k+1] << "\n";
}
