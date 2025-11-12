#include <bits/stdc++.h>
using namespace std;

struct AirConditioner {
    int a;
    int b;
    int p;
    int m;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int required[101];
    memset(required, 0, sizeof(required));

    for(int i = 0; i < N; ++i){
        int s, t, c;
        cin >> s >> t >> c;
        for(int j = s; j <= t; ++j){
            required[j] = c;
        }
    }

    vector<AirConditioner> ACs(M);
    for(int i = 0; i < M; ++i){
        cin >> ACs[i].a >> ACs[i].b >> ACs[i].p >> ACs[i].m;
    }

    int minCost = INT32_MAX;

    for(int mask = 0; mask < (1 << M); ++mask){
        int cooling[101];
        memset(cooling, 0, sizeof(cooling));

        int currentCost = 0;

        for(int i = 0; i < M; ++i){
            if(mask & (1 << i)){
                currentCost += ACs[i].m;
                for(int j = ACs[i].a; j <= ACs[i].b; ++j){
                    cooling[j] += ACs[i].p;
                }
            }
        }

        bool valid = true;

        for(int j = 1; j <= 100; ++j){
            if(required[j] > 0 && cooling[j] < required[j]){
                valid = false;
                break;
            }
        }

        if(valid){
            if(currentCost < minCost){
                minCost = currentCost;
            }
        }
    }

    cout << minCost;
}