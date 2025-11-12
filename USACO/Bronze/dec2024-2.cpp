#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

struct State {
    vector<vector<vector<bool>>> cheese;
    vector<vector<int>> lineCountXZ, lineCountXY;
    int n, total;
    
    State(int size) : n(size) {
        cheese = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n, true)));
        lineCountXZ = vector<vector<int>>(n, vector<int>(n, n));
        lineCountXY = vector<vector<int>>(n, vector<int>(n, n));
        total = 0;
    }
    
    void remove(int x, int y, int z) {
        cheese[x][y][z] = false;
        
        lineCountXZ[x][z]--;
        if (lineCountXZ[x][z] == 0) total++;
        
        lineCountXY[x][y]--;
        if (lineCountXY[x][y] == 0) total++;
        
        bool isValid = true;
        for (int i = 0; i < n && isValid; i++) {
            if (cheese[i][y][z]) isValid = false;
        }
        if (isValid) total++;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    
    State state(n);
    
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        state.remove(x, y, z);
        cout << state.total << "\n";
    }
}