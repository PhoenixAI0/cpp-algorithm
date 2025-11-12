#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    
    int n = a.length();
    int m = b.length();
    vector<int> result(n + m, 0);
    
    vector<int> num1(n), num2(m);
    for(int i = 0; i < n; i++) {
        num1[i] = a[n-1-i] - '0';
    }
    for(int i = 0; i < m; i++) {
        num2[i] = b[m-1-i] - '0';
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result[i+j] += num1[i] * num2[j];
        }
    }
    
    for(int i = 0; i < n+m-1; i++) {
        result[i+1] += result[i] / 10;
        result[i] %= 10;
    }
    
    int start = n+m-1;
    while(start > 0 && result[start] == 0) {
        start--;
    }
    
    for(int i = start; i >= 0; i--) {
        cout << result[i];
    }
    cout << "\n";
}