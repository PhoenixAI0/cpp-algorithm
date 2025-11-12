#include <bits/stdc++.h>
using namespace std;

string add(const string& A, const string& B) {
    int i = (int)A.size() - 1, j = (int)B.size() - 1, carry = 0;
    string out;
    while (i >= 0 || j >= 0 || carry) {
        int da = (i >= 0 ? A[i] - '0' : 0);
        int db = (j >= 0 ? B[j] - '0' : 0);
        int s = da + db + carry;
        out.push_back(char('0' + (s % 10)));
        carry = s / 10;
        --i; --j;
    }
    reverse(out.begin(), out.end());
    return out;
}

int main() {
    int n; cin >> n;
    if (n == 1) {cout << 1 << "\n";return 0;}
    string a = "1", b = "2";
    for (int i = 3; i <= n; i++) {
        string c = add(a, b);
        a = b;
        b = c;
    }
    cout << b << "\n";
}
