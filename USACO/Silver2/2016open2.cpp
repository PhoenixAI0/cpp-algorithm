#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> diamonds(n);
    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }
    
    sort(diamonds.begin(), diamonds.end());
    
    vector<int> maxLeft(n, 0);
    vector<int> maxRight(n, 0);
    
    int left = 0;
    for (int right = 0; right < n; right++) {
        while (diamonds[right] - diamonds[left] > k) {
            left++;
        }
        int windowSize = right - left + 1;
        maxLeft[right] = (right > 0 ? maxLeft[right-1] : 0);
        maxLeft[right] = max(maxLeft[right], windowSize);
    }
    
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i], maxLeft[i-1]);
    }
    
    int right = n - 1;
    for (int left = n - 1; left >= 0; left--) {
        while (diamonds[right] - diamonds[left] > k) {
            right--;
        }
        int windowSize = right - left + 1;
        maxRight[left] = (left < n - 1 ? maxRight[left+1] : 0);
        maxRight[left] = max(maxRight[left], windowSize);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i], maxRight[i+1]);
    }
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        int leftCase = maxLeft[i];
        int rightCase = (i + 1 < n) ? maxRight[i + 1] : 0;
        answer = max(answer, leftCase + rightCase);
    }
    
    answer = max(answer, maxLeft[n-1]);
    
    cout << answer << "\n";
}
