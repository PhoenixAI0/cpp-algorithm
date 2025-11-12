#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> fav(n), sec(n);
    for (int i = 0; i < n; i++) {
        cin >> fav[i] >> sec[i];
    }
    
    vector<int> ans(n + 1, 0);
    vector<int> taken(m + 1, -1);
    
    for (int i = n - 1; i >= 0; i--) {
        int cnt = ans[i + 1];
        int cur = i;
        int cereal = fav[cur];
        while (cereal != -1) {
            if (taken[cereal] == -1) {
                taken[cereal] = cur;
                cnt++;
                break;
            }
            if (taken[cereal] < cur) {
                break;
            }
            swap(cur, taken[cereal]);
            if (cereal == fav[cur])
                cereal = sec[cur];
            else
                cereal = -1;
        }
        ans[i] = cnt;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}