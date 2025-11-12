#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<double, double>> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i].first >> coins[i].second;
    }
    sort(coins.begin(), coins.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
        return (a.second / a.first) > (b.second / b.first);
    });
    double total = 0.0;
    for (int i = 0; i < n && t > 0; ++i) {
        double w = coins[i].first, v = coins[i].second;
        if (t >= w) {
            total += v;
            t -= w;
        } else {
            total += v / w * t;
            break;
        }
    }
    cout << fixed << setprecision(2) << total << endl;
}
