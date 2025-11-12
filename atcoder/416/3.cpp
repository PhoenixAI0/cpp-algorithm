#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, X;
    cin >> N >> K >> X;
    
    vector<string> S(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    
    vector<string> results;
    function<void(vector<int>&, int)> generate = [&](vector<int>& sequence, int pos) {
        if (pos == K) {
            string concatenated = "";
            for (int i = 0; i < K; i++) {
                concatenated += S[sequence[i]];
            }
            results.push_back(concatenated);
            return;
        }
        
        for (int i = 1; i <= N; i++) {
            sequence[pos] = i;
            generate(sequence, pos + 1);
        }
    };
    
    vector<int> sequence(K);
    generate(sequence, 0);
    
    sort(results.begin(), results.end());
    
    cout << results[X - 1] << '\n';
}
