#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> dims(n);
    for (int i = 0; i < n; i++){
        cin >> dims[i];
    }
    
    int total = 1;
    for (int i = 0; i < n; i++){
        total *= dims[i];
    }
    
    map<vector<int>, int> S;
    
    for (int idx = 0; idx < total; idx++){
        vector<int> coords(n);
        for (int i = 0; i < n; i++){
            cin >> coords[i];
        }
        int val;
        cin >> val;
        
        vector<int> key;
        key.reserve(n - 1);
        for (int i = 0; i < n; i++){
            if(i == x) continue;
            key.push_back(coords[i]);
        }
        S[key] += val;
    }
    
    for (auto &entry : S){
        for (int coord : entry.first){
            cout << coord << " ";
        }
        cout << entry.second << "\n";
    }
}