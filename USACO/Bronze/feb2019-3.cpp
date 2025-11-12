#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N;
    cin >> N;
    vector<tuple<string, int, int>> segments(N);
    for (int i = 0; i < N; ++i) {
        string t;
        int low, high;
        cin >> t >> low >> high;
        segments[i] = make_tuple(t, low, high);
    }

    vector<pair<int, int>> ranges(N + 2);
    ranges[N + 1] = {0, 1e9};

    for (int i = N; i > 0; --i) {
        string t;
        int lo, hi;
        tie(t, lo, hi) = segments[i - 1];
        auto[nmin, nmax] = ranges[i + 1];

        int rmin, rmax;
        if (t == "none") {
            rmin = max(nmin, lo);
            rmax = min(nmax, hi);
        } else if (t == "on") {
            rmin = nmin - hi;
            rmax = nmax - lo;
        } else {
            rmin = nmin + lo;
            rmax = nmax + hi;
        }

        rmin = max(rmin, 0);
        rmax = max(rmax, 0);
        ranges[i] = {rmin, rmax};
    }

    ranges[0] = ranges[1];
    auto[X0_min, X0_max] = ranges[0];

    int cur_min = X0_min, cur_max = X0_max;
    for (int i = 1; i <= N; ++i) {
        string t;
        int lo, hi;
        tie(t, lo, hi) = segments[i - 1];

        if (t == "none") {
            cur_min = max(cur_min, lo);
            cur_max = min(cur_max, hi);
        } else if (t == "on") {
            cur_min += lo;
            cur_max += hi;
        } else {
            cur_min -= hi;
            cur_max -= lo;
        }

        cur_min = max(cur_min, 0);
        cur_max = max(cur_max, 0);
    }

    auto[XNplus1_min, XNplus1_max] = make_pair(cur_min, cur_max);
    ranges[N + 1] = {XNplus1_min, XNplus1_max};

    cout << X0_min << " " << X0_max << "\n";
    cout << XNplus1_min << " " << XNplus1_max << "\n";
}