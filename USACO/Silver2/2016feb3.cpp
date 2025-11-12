#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    
    int X, Y, K, M;
    cin >> X >> Y >> K >> M;
    
    queue<tuple<int, int, int>> q; 
    set<pair<int, int>> visited;
    set<int> possible_totals;
    
    q.push({0, 0, 0});
    visited.insert({0, 0});
    possible_totals.insert(0);
    
    while (!q.empty()) {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int ops = get<2>(q.front());
        q.pop();
        
        if (ops == K) continue;
        
        vector<pair<int, int>> next_states = {
            {X, b},        
            {a, Y},        
            {0, b},        
            {a, 0},        
            {max(0, a - (Y - b)), min(Y, a + b)}, 
            {min(X, a + b), max(0, b - (X - a))}
        };
        
        for (int i = 0; i < next_states.size(); i++) {
            int na = next_states[i].first;
            int nb = next_states[i].second;
            if (visited.find({na, nb}) == visited.end()) {
                visited.insert({na, nb});
                possible_totals.insert(na + nb);
                q.push(make_tuple(na, nb, ops + 1));
            }
        }
    }
    
    int min_error = INT_MAX;
    for (int total : possible_totals) min_error = min(min_error, abs(M - total));
    cout << min_error << "\n";
}
