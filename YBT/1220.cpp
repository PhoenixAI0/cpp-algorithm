#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string str[25];
int ansCount[25];

int check(string s1, string s2) {
    for (int i = s1.size() - 1; i >= 0; --i) {
        if (s1[i] == s2[0]) {
            int index = i;
            for (int j = 0; j < s2.size(); ++j) {
                if (s1[index] == s2[j]) index++;
                else break;
            }
            if (index == s1.size()) {
                return index - i;
            }
        }
    }
    return 0;
}

void search(string s, int len) {
    ans = max(ans, len);
    for (int i = 0; i < n; ++i) {
        if (ansCount[i] == 2)
            continue;
        int l = check(s, str[i]);
        if (l) {
            ansCount[i]++;
            search(str[i], len + str[i].size() - l);
            ansCount[i]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> str[i];
    string start;
    cin >> start;
    search(start, 1);
    cout << ans;
}