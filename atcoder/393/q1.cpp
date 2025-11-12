#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<bool, bool> a = {false, false};
    string s;
    cin >> s;
    if (s == "sick") a.first = true;
    cin >> s;
    if (s == "sick") a.second = true;
    if (a.first && a.second) cout << 1 << endl;
    else if (a.first) cout << 2 << endl;
    else if (a.second) cout << 3 << endl;
    else cout << 4 << endl;
}