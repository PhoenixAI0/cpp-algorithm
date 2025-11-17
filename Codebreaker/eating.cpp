// https://codebreaker.xyz/problem/eating
// Reflections:
// 1. There is no hash for <pair<string, string>>, so it cannot be used with unordered_set.
// 2. We need an unordered datastructure for O(1) rather than O(log n)
// 3. unordered_map works bcs there is a hash for string.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<string, set<string>> m;
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        if (m[a].find(b) == m[a].end()) {
            m[a].insert(b);
            cout << "YES\n";
        } else cout << "NO\n";
    }
}


// Previous code using a set
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; cin >> n;
//     set<pair<string, string>> s;
//     for (int i = 0; i < n; i++) {
//         string a, b; cin >> a >> b;
//         if (s.find({a, b}) == s.end()) {
//             s.insert({a, b});
//             cout << "YES\n";
//         } else cout << "NO\n";
//     }
// }
//
