#include <bits/stdc++.h>
using namespace std;

string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> result(a.size() + b.size(), 0);

    for (size_t i = 0; i < a.size(); ++i) {
        int da = a[i] - '0';
        for (size_t j = 0; j < b.size(); ++j) {
            result[i + j] += da * (b[j] - '0');
        }
    }

    for (size_t i = 0; i + 1 < result.size(); ++i) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    int k = (int)result.size() - 1;
    while (k > 0 && result[k] == 0) --k;

    string ans;
    ans.reserve(k + 1);
    for (int i = k; i >= 0; --i) ans.push_back(char('0' + result[i]));
    return ans;
}

string factorial(int n) {
    string a = "1";
    for (int i = 2; i <= n; i++) {
        a = multiply(a, to_string(i));
    }
    return a;
}

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
    string result = "0";
    for (int i = 1; i <= n; i++) {
        result = add(result, factorial(i));
    }
    while (result[0] == '0') {
        result.erase(0, 1);
    }
    cout << result << endl;
}
