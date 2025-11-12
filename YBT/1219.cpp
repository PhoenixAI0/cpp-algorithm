#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, 
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

void search(pair<int, int> location, pair<int, int> dimensions, set<pair<int, int>>& visited, int& numAnswers) {
    if (visited.size() == dimensions.first * dimensions.second) {
        numAnswers++;
        return;
    }

    for (auto &move : moves) {
        int newX = location.first + move.first;
        int newY = location.second + move.second;

        if (newX >= 0 && newX < dimensions.first && newY >= 0 && newY < dimensions.second && !visited.count({newX, newY})) {
            visited.insert({newX, newY});
            search({newX, newY}, dimensions, visited, numAnswers);
            visited.erase({newX, newY});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        
        pair<int, int> dimensions = {n, m};
        set<pair<int, int>> visited;
        int numAnswers = 0;
        
        visited.insert({x, y});
        search({x, y}, dimensions, visited, numAnswers);

        cout << numAnswers << '\n';
    }
}