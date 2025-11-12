#include <bits/stdc++.h>
using namespace std;

bool solve(const string &path) {
    int x = 0, y = 0;
    vector<pair<int, int>> points = {{x, y}};
    
    for (char c : path) {
        if (c == 'N') y++;
        if (c == 'S') y--;
        if (c == 'E') x++;
        if (c == 'W') x--;
        points.emplace_back(x, y);
    }
    
    int area = 0;
    for (int i = 0; i < points.size() - 1; ++i) {
        area += points[i].first * points[i + 1].second;
        area -= points[i].second * points[i + 1].first;
    }

    return area < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string path;
        cin >> path;
        if (solve(path)) {
            cout << "CW\n";
        } else {
            cout << "CCW\n";
        }
    }
}