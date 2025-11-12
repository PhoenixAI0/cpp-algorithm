#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        string cows;
        cin >> cows;

        string result(N, '.');
        int patches = 0;

        vector<bool> coveredG(N, false), coveredH(N, false);

        for (int i = 0; i < N; ++i) {
            if ((cows[i] == 'G' && coveredG[i]) || (cows[i] == 'H' && coveredH[i])) {
                continue;
            }

            char patchType = cows[i];
            int patchPos = min(N - 1, i + K);

            while (patchPos >= i && result[patchPos] != '.') {
                --patchPos;
            }

            if (patchPos < 0) continue;

            result[patchPos] = patchType;
            patches++;

            for (int j = max(0, patchPos - K); j <= min(N - 1, patchPos + K); ++j) {
                if (cows[j] == 'G' && patchType == 'G') {
                    coveredG[j] = true;
                } else if (cows[j] == 'H' && patchType == 'H') {
                    coveredH[j] = true;
                }
            }
        }

        cout << patches << "\n" << result << "\n";
    }
}