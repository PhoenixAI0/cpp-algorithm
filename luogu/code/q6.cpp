#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    long long ans = 0;
    for (int num : a) {
        int target = num + c;
        ans += freq[target];
        if (target == num) {
            ans--;
        }
    }
    
    cout << ans << "\n";
}