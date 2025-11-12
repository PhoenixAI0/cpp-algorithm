#include <bits/stdc++.h>
using namespace std;
void factorize(int n, vector<int>& factors) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            factorize(n / i, factors);
            return;
        }
    }
    factors.push_back(n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> factors;
    factorize(n, factors);
    sort(factors.begin(), factors.end());
    map<int, int> freq;
    for (int i = 0; i < factors.size(); i++) {
        freq[factors[i]]++;
    }
    string s;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second == 1) {
            s += to_string(it->first) + "*";
            continue;
        }
        s += to_string(it->first) + "^" + to_string(it->second) + "*";
    }
    cout << s.substr(0, s.size() - 1) << endl;
}
