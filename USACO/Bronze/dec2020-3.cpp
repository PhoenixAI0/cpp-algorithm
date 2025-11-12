#include <bits/stdc++.h>
using namespace std;

struct Cow {
    char dir;
    long long x;
    long long y;
};

struct Event {
    long long total_time;
    int north_cow;
    int east_cow;
    long long t_n;
    long long t_e;

    bool operator<(const Event& other) const {
        return total_time < other.total_time;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<Cow> cows(N);
    
    for(int i=0; i<N; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
    }

    vector<Event> events;

    for(int i=0; i<N; i++){
        if(cows[i].dir == 'N'){
            for(int j=0; j<N; j++){
                if(cows[j].dir == 'E'){
                    if(cows[j].x < cows[i].x && cows[i].y < cows[j].y){
                        long long t_n = cows[j].y - cows[i].y;
                        long long t_e = cows[i].x - cows[j].x;
                        
                        if(t_n > 0 && t_e > 0){
                            Event e;
                            e.total_time = t_n + t_e;
                            e.north_cow = i;
                            e.east_cow = j;
                            e.t_n = t_n;
                            e.t_e = t_e;
                            events.push_back(e);
                        }
                    }
                }
            }
        }
    }

    sort(events.begin(), events.end());

    const long long INF = 1e18;
    vector<long long> block_step(N, INF);

    for(auto &e: events){
        if(e.t_n == e.t_e){
            continue;
        }
        else if(e.t_n < e.t_e){
            if(block_step[e.north_cow] > e.t_n && block_step[e.east_cow] > e.t_e){
                block_step[e.east_cow] = min(block_step[e.east_cow], e.t_e);
            }
        }
        else {
            if(block_step[e.east_cow] > e.t_e && block_step[e.north_cow] > e.t_n){
                block_step[e.north_cow] = min(block_step[e.north_cow], e.t_n);
            }
        }
    }

    for(int i=0; i<N; i++){
        if(block_step[i] == INF){
            cout << "Infinity\n";
        }
        else{
            cout << block_step[i] << "\n";
        }
    }
}