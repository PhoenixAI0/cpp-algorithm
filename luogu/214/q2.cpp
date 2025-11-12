#include <iostream>
using namespace std;

int main(){
    long long n, x, y;
    cin >> n >> x >> y;
    
    long long d_cw = (y - x + n) % n;
    if(d_cw == 0) d_cw = n;
    
    long long d_ccw = n - d_cw;
    
    if(d_cw < d_ccw) {
        cout << "Clockwise Loop";
    } else if(d_cw > d_ccw) {
        cout << "Counter-clockwise Loop";
    } else {
        cout << "\"Wonderful\"";
    }
}