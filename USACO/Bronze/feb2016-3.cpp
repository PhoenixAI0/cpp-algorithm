#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N, B;
    cin >> N >> B;

    vector<pair<int,int>> cows(N);
    vector<int> uniqueX, uniqueY;

    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
        uniqueX.push_back(cows[i].first);
        uniqueY.push_back(cows[i].second);
    }

    sort(uniqueX.begin(), uniqueX.end());
    uniqueX.erase(unique(uniqueX.begin(), uniqueX.end()), uniqueX.end());

    sort(uniqueY.begin(), uniqueY.end());
    uniqueY.erase(unique(uniqueY.begin(), uniqueY.end()), uniqueY.end());

    vector<int> candidateX;
    candidateX.push_back(uniqueX.front() - 1);
    candidateX.push_back(uniqueX.back() + 1);

    for (int i = 0; i + 1 < (int)uniqueX.size(); i++) {
        int a = uniqueX[i] + 1;
        candidateX.push_back(a);
    }

    sort(candidateX.begin(), candidateX.end());
    candidateX.erase(unique(candidateX.begin(), candidateX.end()), candidateX.end());

    vector<int> candidateY;
    candidateY.push_back(uniqueY.front() - 1);
    candidateY.push_back(uniqueY.back() + 1);
    for (int i = 0; i + 1 < (int)uniqueY.size(); i++) {
        int b = uniqueY[i] + 1;
        candidateY.push_back(b);
    }
    sort(candidateY.begin(), candidateY.end());
    candidateY.erase(unique(candidateY.begin(), candidateY.end()), candidateY.end());

    int answer = INT_MAX;

    for (int a : candidateX) {
        for (int b : candidateY) {
            int cntNW = 0, cntNE = 0, cntSW = 0, cntSE = 0;
            for (auto &c : cows) {
                int x = c.first;
                int y = c.second;
                if (x < a && y > b) cntNW++;
                else if (x > a && y > b) cntNE++;
                else if (x < a && y < b) cntSW++;
                else if (x > a && y < b) cntSE++;
            }
            int M = max({cntNW, cntNE, cntSW, cntSE});
            answer = min(answer, M);
        }
    }

    cout << answer << "\n";
}