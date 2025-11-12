#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    vector<vector<int>> stars(N, vector<int>(N, 0));  // 1 if star present in original photo
    int count = 0;
    bool possible = true;
    
    // First pass: Place stars for black pixels
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'B') {
                // For a black pixel, we need at least two stars overlapping
                int prev_i = i - B;
                int prev_j = j - A;
                
                if (prev_i >= 0 && prev_i < N && prev_j >= 0 && prev_j < N) {
                    // Can have a star move here
                    if (grid[prev_i][prev_j] != 'W') {
                        stars[prev_i][prev_j] = 1;
                        count++;
                    }
                }
                // Always need a star here for black pixel
                stars[i][j] = 1;
                count++;
            }
        }
    }
    
    // Second pass: Place stars for gray pixels
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'G') {
                bool explained = false;
                
                // Check if already explained by a star moving here
                int prev_i = i - B;
                int prev_j = j - A;
                if (prev_i >= 0 && prev_i < N && prev_j >= 0 && prev_j < N && stars[prev_i][prev_j]) {
                    explained = true;
                }
                
                // Check if explained by a star here that moves away
                int next_i = i + B;
                int next_j = j + A;
                if (next_i < N && next_j < N && stars[i][j]) {
                    explained = true;
                }
                
                // If not explained, place a star here
                if (!explained && !stars[i][j]) {
                    stars[i][j] = 1;
                    count++;
                }
            }
        }
    }
    
    // Verify solution
    vector<vector<int>> final_photo(N, vector<int>(N, 0));
    
    // Count stars in original positions
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (stars[i][j]) {
                final_photo[i][j]++;
            }
        }
    }
    
    // Count stars after movement
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (stars[i][j]) {
                int new_i = i + B;
                int new_j = j + A;
                if (new_i < N && new_j < N) {
                    final_photo[new_i][new_j]++;
                }
            }
        }
    }
    
    // Final verification
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'W' && final_photo[i][j] != 0) {
                possible = false;
                break;
            }
            if (grid[i][j] == 'G' && final_photo[i][j] != 1) {
                possible = false;
                break;
            }
            if (grid[i][j] == 'B' && final_photo[i][j] < 2) {
                possible = false;
                break;
            }
        }
        if (!possible) break;
    }
    
    // Extra verification: check if any star placement creates unwanted overlaps
    if (possible) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (stars[i][j]) {
                    // Check if this star's movement creates any invalid states
                    int new_i = i + B;
                    int new_j = j + A;
                    if (new_i < N && new_j < N) {
                        if (grid[new_i][new_j] == 'W') {
                            possible = false;
                            break;
                        }
                    }
                }
            }
            if (!possible) break;
        }
    }
    
    cout << (possible ? count : -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
} 