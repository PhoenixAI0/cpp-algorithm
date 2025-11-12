#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    vector<bool> current(k, false);

    int r1 = (arr[0] % k + k) % k;
    int r2 = ((-arr[0]) % k + k) % k;
    current[r1] = true;
    current[r2] = true;

    for (int i = 1; i < N; i++) {
        vector<bool> next(k, false);
        int x = arr[i] % k;  
        if(x < 0) x += k;

        for (int r = 0; r < k; r++){
            if (current[r]) {
                int r_plus  = (r + x) % k;
                int r_minus = (r - x + k) % k;
                next[r_plus] = true;
                next[r_minus] = true;
            }
        }
        current = next;
    }
    if (current[0]) cout << "YES\n";
    else cout << "NO\n";
}