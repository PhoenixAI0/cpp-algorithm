#include <bits/stdc++.h>
using namespace std;

bool cow_ends_infected[101];  // final state of each cow
int N, T;
int cowx[251], cowy[251];    // handshake data at each time t

// Check if this patient zero and K value are consistent with final state
bool consistent_with_data(int patient_zero, int K) {
    vector<bool> infected(N + 1, false);
    vector<int> handshakes(N + 1, 0);
    infected[patient_zero] = true;
    
    // Simulate all possible interactions over time
    for (int t = 0; t <= 250; t++) {
        int x = cowx[t], y = cowy[t];
        if (x > 0) {  // if there's an interaction at this time
            if (infected[x]) handshakes[x]++;
            if (infected[y]) handshakes[y]++;
            if (infected[x] && handshakes[x] <= K) infected[y] = true;
            if (infected[y] && handshakes[y] <= K) infected[x] = true;
        }
    }
    
    // Check if final state matches given state
    for (int i = 1; i <= N; i++) {
        if (infected[i] != cow_ends_infected[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    
    string s;
    cin >> N >> T >> s;
    
    // Convert final state string to boolean array
    for (int i = 1; i <= N; i++) {
        cow_ends_infected[i] = (s[i-1] == '1');
    }
    
    // Read and store interactions
    memset(cowx, 0, sizeof(cowx));
    memset(cowy, 0, sizeof(cowy));
    for (int i = 0; i < T; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        cowx[t] = x;
        cowy[t] = y;
    }
    
    vector<bool> possible_i(N + 1, false);
    vector<bool> possible_K(252, false);
    
    // Try each cow as patient zero and each K value
    for (int i = 1; i <= N; i++) {
        for (int k = 0; k <= 251; k++) {
            if (consistent_with_data(i, k)) {
                possible_i[i] = true;
                possible_K[k] = true;
            }
        }
    }
    
    // Count possible patient zeros
    int num_patient_zero = 0;
    for (int i = 1; i <= N; i++) {
        if (possible_i[i]) num_patient_zero++;
    }
    
    // Find K range
    int lower_K = 251, upper_K = 0;
    for (int k = 0; k <= 251; k++) {
        if (possible_K[k]) {
            upper_K = k;
        }
    }
    for (int k = 251; k >= 0; k--) {
        if (possible_K[k]) {
            lower_K = k;
        }
    }
    
    cout << num_patient_zero << " " << lower_K << " ";
    if (upper_K == 251) cout << "Infinity\n";
    else cout << upper_K << "\n";
    
    return 0;
} 