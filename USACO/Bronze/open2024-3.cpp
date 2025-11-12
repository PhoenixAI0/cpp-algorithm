#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> h(N-1);
        for(auto &x : h) cin >> x;
        // Initialize leftover
        int L = h[N-2];
        // Initialize deque
        deque<int> D;
        D.push_back(L);
        // Initialize sorted set U = {1..N} \ {L}
        set<int> U;
        for(int i=1;i<=N;i++) if(i != L) U.insert(i);
        bool possible = true;
        // Iterate from N-2 down to 0
        for(int i=N-3;i>=0;i--){
            int x = h[i];
            // Initialize candidates
            // We will keep track of 'L' and 'R' scenarios
            bool canL = false, canR = false;
            int y = -1, z = -1;
            // 'L' scenario
            if(!D.empty() && D.front() == x){
                // Find smallest y in U where y > D.back()
                if(!D.empty()){
                    int current_back = D.back();
                    auto it = U.upper_bound(current_back);
                    if(it != U.end()){
                        y = *it;
                        canL = true;
                    }
                }
            }
            // 'R' scenario
            if(!D.empty() && D.back() == x){
                // Find smallest z in U where z >= D.front()
                if(!D.empty()){
                    int current_front = D.front();
                    auto it = U.lower_bound(current_front);
                    if(it != U.end()){
                        z = *it;
                        canR = true;
                    }
                }
            }
            // Decide which scenario to choose
            if(!canL && !canR){
                possible = false;
                break;
            }
            if(canL && canR){
                // Compare y vs D.front()
                // To minimize the front of the deque, prefer 'R' if possible
                // because 'R' keeps D.front() as is, which is better
                // Only choose 'L' if y < D.front()
                if(y < D.front()){
                    // Choose 'L'
                    D.push_front(y);
                    U.erase(y);
                }
                else{
                    // Choose 'R'
                    D.push_back(z);
                    U.erase(z);
                }
            }
            else if(canL){
                // Choose 'L'
                D.push_front(y);
                U.erase(y);
            }
            else{
                // Choose 'R'
                D.push_back(z);
                U.erase(z);
            }
        }
        if(!possible){
            cout << "-1\n";
            continue;
        }
        // Now, check if all elements are used
        if(D.size() != N){
            cout << "-1\n";
            continue;
        }
        // Check if all elements are unique and in 1..N
        vector<bool> seen(N+1, false);
        bool valid = true;
        for(auto &x : D){
            if(x <1 || x >N || seen[x]){
                valid = false;
                break;
            }
            seen[x] = true;
        }
        if(!valid){
            cout << "-1\n";
            continue;
        }
        // Output the deque
        for(int i=0;i<N;i++){
            cout << D[i] << (i<N-1?" ":"\n");
        }
    }
}