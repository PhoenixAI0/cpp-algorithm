#include <bits/stdc++.h>
using namespace std;
 
struct Particle {
    long long x, y;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    int N; 
    cin >> N;
    vector<Particle> parts(N);
    for (int i=0; i<N; i++){
        cin >> parts[i].x >> parts[i].y;
    }
    sort(parts.begin(), parts.end(), [](const Particle &a, const Particle &b){
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    });
    
    vector<long long> groups;
    
    for (int i = 0; i < N; i++){
        long long Y = parts[i].y;
        int mergeCount = 0;
        while( mergeCount < (int)groups.size() && groups[mergeCount] <= Y )
            mergeCount++;
        if( mergeCount > 0 ){
            long long newMin = groups[0];
            groups.erase(groups.begin(), groups.begin() + mergeCount);
            auto it = lower_bound(groups.begin(), groups.end(), newMin);
            groups.insert(it, newMin);
        } else {
            auto it = lower_bound(groups.begin(), groups.end(), Y);
            groups.insert(it, Y);
        }
    }
    
    cout << groups.size() << "\n";
}