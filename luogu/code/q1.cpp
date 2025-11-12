#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> prize;
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        prize.insert(num);
    }
    
    int ans[7] = {0};
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 7; ++j) {
            int num;
            cin >> num;
            if (prize.count(num)) {
                cnt++;
            }
        }
        if (cnt >= 1) {
            ans[7 - cnt]++;
        }
    }
    
    cout << ans[0];
    for (int i = 1; i < 7; ++i) {
        cout << " " << ans[i];
    }
    cout << "\n";
}