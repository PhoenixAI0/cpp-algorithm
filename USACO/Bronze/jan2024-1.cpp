#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        vector<bool> done(N, false);
        for (int i = 0; i < N; i++){
            cin >> a[i];
            a[i]--;
            if (i > 0 && a[i] == a[i-1] || i > 1 && a[i] == a[i-2]) done[a[i]] = true;
        }
 
        string output = "";
        for (int i = 0; i < N; i++) {
            if (done[i]) {
                output += to_string(i + 1) + " ";
            }
        }
        if (output.empty()) output = "-1";
        else output.pop_back();
        cout << output;
        cout << '\n';
    }
}