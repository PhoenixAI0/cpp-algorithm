#include <bits/stdc++.h>
using namespace std;

int search(vector<pair<int, int>> positions, int k) {
    if (k == 0) return 1; // Base case: Successfully placed all pieces
    int answers = 0;

    for (size_t i = 0; i < positions.size(); i++) {
        auto position = positions[i];

        // Create a new vector of valid positions after placing the piece
        vector<pair<int, int>> new_positions;
        for (size_t j = i + 1; j < positions.size(); j++) {
            if (positions[j].first != position.first && positions[j].second != position.second) {
                new_positions.push_back(positions[j]);
            }
        }

        // Recur with one less piece to place
        answers += search(new_positions, k - 1);
    }

    return answers;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (true) {
        cin >> n >> k;
        if (n == -1 && k == -1) break;

        vector<pair<int, int>> positions;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char buffer;
                cin >> buffer;
                if (buffer == '#') {
                    positions.push_back({i, j});
                }
            }
        }
        cout << search(positions, k) << "\n";
    }
}