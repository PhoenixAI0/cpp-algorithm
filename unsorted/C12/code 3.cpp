#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> buckets(26, 0);
    for (int i = 0; i < s.size(); i++) {
        buckets[s[i] - 'a']++;
    }
    int max = 0;
    char character;
    for (int i = 0; i < 26; i++) {
        if (buckets[i] > max) {
            max = buckets[i];
            character = 'a' + i;
        }
    }
    cout << character << " " << max << endl;
}
