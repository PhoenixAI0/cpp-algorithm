#include <bits/stdc++.h>
using namespace std;

static string decode(const string &s, int &i) {
    string res;
    while (i < (int)s.size() && s[i] != ']') {
        if (s[i] == '[') {
            ++i;
            int num = 0;
            while (i < (int)s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            string inner = decode(s, i);
            if (i < (int)s.size() && s[i] == ']') ++i;
            for (int k = 0; k < num; ++k) res += inner;
        } else {
            res += s[i++];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; 
    cin >> s;
    int idx = 0;
    string out = decode(s, idx);
    cout << out << '\n';
}
