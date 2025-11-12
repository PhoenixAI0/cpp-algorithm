#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X, Y, K;
    cin >> X >> Y >> K;
    
    int maxTaste = -1;
    long long ways = 0;
    
    for (int s = 1; s <= X + Y; s++){
        int L = max(0, s - Y);
        int R = min(X, s - 1);
        if (L > R) continue;
        int cnt = R - L + 1;
        
        for (int z = 0; z <= K; z++){
            int taste = s ^ z;
            if (taste > maxTaste) {
                maxTaste = taste;
                ways = cnt;
            } else if (taste == maxTaste) {
                ways += cnt;
            }
        }
    }
    
    cout << maxTaste << "\n" << ways;
}