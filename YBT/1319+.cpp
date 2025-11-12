#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;

    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<int>> taps;
    for (int i = 0; i < r; i++) {
        taps.push(0);
    }
    int total_time = 0;

    for (int time : times) {
        int current_load = taps.top();
        taps.pop();
        current_load += time;
        total_time += current_load;
        taps.push(current_load);
    }

    cout << total_time << "\n";
}