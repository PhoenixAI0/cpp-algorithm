#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<pair<int,int>> ops(M);
    for (int i = 0; i < M; i++) {
        cin >> ops[i].first >> ops[i].second;
    }
    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        order[i] = i + 1;
    }
    for (int i = 0; i < M; i++) {
        int L = ops[i].first, R = ops[i].second;
        reverse(order.begin() + L - 1, order.begin() + R);
    }
    vector<int> p(N);
    for (int j = 0; j < N; j++) {
        p[order[j] - 1] = j;
    }
    vector<bool> visited(N, false);
    vector<int> final_order(N, 0);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int cur = i;
            while (!visited[cur]) {
                visited[cur] = true;
                cycle.push_back(cur);
                cur = p[cur];
            }
            int cycle_size = cycle.size();
            int shift = K % cycle_size;
            for (int j = 0; j < cycle_size; j++) {
                int orig_idx = cycle[j];
                int final_pos = cycle[(j + shift) % cycle_size];
                final_order[final_pos] = orig_idx + 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << final_order[i] << "\n";
    }
}