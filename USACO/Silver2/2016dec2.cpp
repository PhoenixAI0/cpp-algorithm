#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    
    int n;
    cin >> n;
    
    map<string, vector<pair<string, string>>> prefixMap;
    
    vector<pair<string, string>> cities;
    
    for (int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        cities.push_back({city, state});
        
        string prefix = city.substr(0, 2);
        prefixMap[prefix].push_back({city, state});
    }
    
    int count = 0;
    
    for (const auto& cityPair : cities) {
        string city = cityPair.first;
        string state = cityPair.second;
        string prefix = city.substr(0, 2);
        
        if (prefixMap.count(state)) {
            for (const auto& otherPair : prefixMap[state]) {
                string otherCity = otherPair.first;
                string otherState = otherPair.second;
                if (otherState == prefix && otherState != state) {
                    count++;
                }
            }
        }
    }
    
    cout << count / 2 << endl;
}
