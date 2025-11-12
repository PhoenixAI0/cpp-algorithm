#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> segments;
    int region = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            region++;
        } else {
            if (region > 0) {
                segments.push_back(region);
            }
            region = 0;
        }
    }
    if (region > 0) {
        segments.push_back(region);
    }

    int numInfected = n;
    for (int window = 1; window <= n; window += 2) {
        int tempInfected = 0;
        bool valid = true;

        for (size_t i = 0; i < segments.size(); i++) {
            int block = segments[i];

            if ((i == 0 && s[0] == '1') || (i == segments.size() - 1 && s[n - 1] == '1')) {
                if (window > block * 2 - 1) {
                    valid = false;
                    break;
                }
            } else {
                if (window > block) {
                    valid = false;
                    break;
                }
            }

            tempInfected += (block + window - 1) / window;
        }

        if (!valid) break;
        numInfected = min(numInfected, tempInfected);
    }

    cout << numInfected << endl;
}
