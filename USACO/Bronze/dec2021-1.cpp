#include <bits/stdc++.h>
using namespace std;

long long countExactlyOne(const string &s, char c) {
    vector<int> pos;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == c) {
            pos.push_back(i);
        }
    }

    if (pos.empty()) return 0LL;
    pos.insert(pos.begin(), -1);
    pos.push_back((int)s.size());

    long long res = 0;

    for (int j = 1; j + 1 < (int)pos.size(); j++) {
        long long L = (long long)pos[j] - pos[j - 1] - 1;
        long long R = (long long)pos[j + 1] - pos[j] - 1;
        long long totalSub = (L + 1) * (R + 1);
        long long subtractLen1 = 1;

        long long subtractLen2 = 0;
        if (L >= 1) subtractLen2++;
        if (R >= 1) subtractLen2++;

        res += (totalSub - subtractLen1 - subtractLen2);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    long long countG = countExactlyOne(s, 'G');
    long long countH = countExactlyOne(s, 'H');

    long long ans = countG + countH;
    cout << ans << "\n";
}