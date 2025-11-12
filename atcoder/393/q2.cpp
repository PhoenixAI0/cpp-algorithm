#include <bits/stdc++.h>
using namespace std;

int count(const string &S) {
    int count = 0;
    int n = S.size();
    
    for (int i = 0; i < n - 2; ++i) { 
        if (S[i] != 'A') continue;
        
        for (int j = i + 1; j < n - 1; ++j) { 
            if (S[j] != 'B') continue;
            
            int k = 2 * j - i; 
            if (k < n && S[k] == 'C') {
                ++count;
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    cout << count(S) << "\n";
}