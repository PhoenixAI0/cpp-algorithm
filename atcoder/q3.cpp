#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    int a = H, b = -1, c = W, d = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '#') {
                a = min(a, i);
                b = max(b, i);
                c = min(c, j);
                d = max(d, j);
            }
        }
    }

    bool valid = true;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i >= a && i <= b && j >= c && j <= d) {
                if (S[i][j] == '.') {
                    valid = false;
                }
            } else {
                if (S[i][j] == '#') {
                    valid = false;
                }
            }
        }
    }

    cout << (valid ? "Yes" : "No") << endl;
}