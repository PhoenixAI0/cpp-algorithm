#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Cow {
    int x;
    int y;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int N;
    cin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++){
        cin >> cows[i].x >> cows[i].y;
    }
    vector<int> xIdx(N), yIdx(N);
    for (int i = 0; i < N; i++){
        xIdx[i] = i;
        yIdx[i] = i;
    }
    sort(xIdx.begin(), xIdx.end(), [&](int a, int b){
        return cows[a].x < cows[b].x;
    });
    sort(yIdx.begin(), yIdx.end(), [&](int a, int b){
        return cows[a].y < cows[b].y;
    });
    ll ans = LLONG_MAX;
    vector<int> candMinX, candMaxX, candMinY, candMaxY;
    for (int i = 0; i < 4; i++){
        candMinX.push_back(cows[xIdx[i]].x);
        candMinY.push_back(cows[yIdx[i]].y);
        candMaxX.push_back(cows[xIdx[N - 1 - i]].x);
        candMaxY.push_back(cows[yIdx[N - 1 - i]].y);
    }
    for (int minX : candMinX) {
        for (int maxX : candMaxX) {
            if (maxX < minX) continue;
            for (int minY : candMinY) {
                for (int maxY : candMaxY) {
                    if (maxY < minY) continue;
                    int removals = 0;
                    for (int i = 0; i < N; i++){
                        if (cows[i].x < minX || cows[i].x > maxX || cows[i].y < minY || cows[i].y > maxY) {
                            removals++;
                            if (removals > 3) break;
                        }
                    }
                    if (removals <= 3) {
                        ll area = (ll)(maxX - minX) * (maxY - minY);
                        ans = min(ans, area);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}