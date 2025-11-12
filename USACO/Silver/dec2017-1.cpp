#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    
    int N; cin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; i++) cin >> scores[i];
    
    vector<ll> sufSum(N);
    vector<int> sufMin(N);
    sufSum[N - 1] = scores[N - 1];
    sufMin[N - 1] = scores[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        sufSum[i] = sufSum[i + 1] + scores[i];
        sufMin[i] = min(scores[i], sufMin[i + 1]);
    }

    ll bestNum = -1;
    ll bestDen = 1;
    vector<int> best;
    
    for (int K = 1; K <= N - 2; K++) {
        int remaining = N - K;
        int denom = remaining - 1;
        ll num = sufSum[K] - sufMin[K];
        if (num * bestDen > bestNum * denom) {
            bestNum = num;
            bestDen = denom;
            best.clear();
            best.push_back(K);
        } else if (num * bestDen == bestNum * denom) {
            best.push_back(K);
        }
    }
    
    for (int K : best) cout << K << "\n";
}