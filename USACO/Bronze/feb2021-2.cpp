#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1001;
bool grid[MAXN][MAXN] = {false};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_comfortable(int x, int y) {
    if (!grid[x][y]) return false;
    int neighbors = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN && grid[nx][ny]) {
            neighbors++;
        }
    }
    return neighbors == 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    int comfortable_count = 0;

    for (const auto& cow : cows) {
        int x = cow.first;
        int y = cow.second;

        // Before adding the new cow, check the comfort status of its neighbors
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN && grid[nx][ny]) {
                if (is_comfortable(nx, ny)) {
                    comfortable_count--;
                }
            }
        }

        // Add the new cow
        grid[x][y] = true;

        // Check the comfort status of the new cow
        if (is_comfortable(x, y)) {
            comfortable_count++;
        }

        // After adding the new cow, check the comfort status of its neighbors again
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN && grid[nx][ny]) {
                if (is_comfortable(nx, ny)) {
                    comfortable_count++;
                }
            }
        }

        // Output the current number of comfortable cows
        cout << comfortable_count << "\n";
    }
}