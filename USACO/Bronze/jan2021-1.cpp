#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string alphabet; cin >> alphabet;
    string s; cin >> s;
    vector<int> numbers;
    for (int i = 0; i < s.size(); i++) {
        numbers.push_back(alphabet.find(s[i]));
    }
    int ans = 0;
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] <= numbers[i-1]) {
            ans++;
        }
    }
    cout << ans + 1 << "\n";
}
