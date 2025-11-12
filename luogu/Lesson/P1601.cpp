#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<char> s;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for (size_t i = 0; i < n; ++i) {
        int da = (i < a.size() ? a[i] - '0' : 0);
        int db = (i < b.size() ? b[i] - '0' : 0);
        int sum = da + db + carry;
        s.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }

    if (carry) s.push_back(char('0' + carry));

    for (int i = (int)s.size() - 1; i >= 0; --i) cout << s[i];
    cout << '\n';
}