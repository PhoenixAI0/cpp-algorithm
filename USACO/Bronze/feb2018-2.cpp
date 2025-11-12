#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pos;
vector<int> pass_to;
vector<int> receives_from;

// Find who each cow passes to
void compute_passes() {
    pass_to.resize(n);
    receives_from.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        int nearest = -1;
        int min_dist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int dist = abs(pos[i] - pos[j]);
            if (dist < min_dist || (dist == min_dist && pos[j] < pos[nearest])) {
                min_dist = dist;
                nearest = j;
            }
        }
        pass_to[i] = nearest;
        receives_from[nearest]++;
    }
}

// Check if two cows pass to each other
bool is_mutual(int i, int j) {
    return pass_to[i] == j && pass_to[j] == i;
}

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    
    cin >> n;
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    
    if (n <= 2) {
        cout << "1\n";
        return 0;
    }
    
    compute_passes();
    
    vector<bool> must_receive(n, false);
    int ans = 0;
    
    // First, handle mutual passing pairs that don't receive from others
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_mutual(i, j) && receives_from[i] == 1 && receives_from[j] == 1) {
                must_receive[i] = true;
                ans++;
            }
        }
    }
    
    // Then handle remaining cows
    vector<bool> covered(n, false);
    for (int i = 0; i < n; i++) {
        if (must_receive[i]) {
            // Mark all cows reachable from i
            int curr = i;
            while (!covered[curr]) {
                covered[curr] = true;
                curr = pass_to[curr];
            }
        }
    }
    
    // Add balls for remaining uncovered cows
    for (int i = 0; i < n; i++) {
        if (!covered[i] && receives_from[i] == 0) {
            ans++;
            int curr = i;
            while (!covered[curr]) {
                covered[curr] = true;
                curr = pass_to[curr];
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}