#include <bits/stdc++.h>
using namespace std;

struct Stu {
    int id;
    int chi;
    int total;
};

int main() {
    int n; 
    if (!(cin >> n)) return 0;
    vector<Stu> a(n);
    for (int i = 0; i < n; i++) {
        int chi, math, eng;
        cin >> chi >> math >> eng;
        a[i] = { i + 1, chi, chi + math + eng };
    }
    sort(a.begin(), a.end(), [](const Stu& x, const Stu& y) {
        if (x.total != y.total) return x.total > y.total;
        if (x.chi   != y.chi)   return x.chi   > y.chi;
        return x.id < y.id;
    });
    int k = min(5, (int)a.size());
    for (int i = 0; i < k; i++) {
        cout << a[i].id << ' ' << a[i].total << '\n';
    }
}