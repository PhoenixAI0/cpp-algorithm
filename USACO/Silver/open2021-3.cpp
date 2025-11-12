#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, L;
    cin >> N >> K >> L;
    vector<int> citations(N);
    for (int i = 0; i < N; i++){
        cin >> citations[i];
    }

    sort(citations.begin(), citations.end(), greater<int>());

    auto canAchieve = [&](int h) -> bool {
        int countQualified = 0;
        ll extraNeeded = 0;

        for (int i = 0; i < N && countQualified < h; i++){
            int c = citations[i];
            if(c >= h){
                countQualified++;
            } else {
                if(c + K < h) continue;
                extraNeeded += (h - c);
                countQualified++;
            }
        }
        if(countQualified < h) return false;
        return extraNeeded <= (ll)K * L;
    };

    int lo = 0, hi = N;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(canAchieve(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << "\n";
}