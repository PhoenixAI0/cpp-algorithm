#include <bits/stdc++.h>
using namespace std;

struct Element {
    int value;
    int classIndex;
    int pos;
};

struct Compare {
    bool operator()(const Element &a, const Element &b) {
        return a.value > b.value;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<vector<int>> classes(n, vector<int>(s));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < s; j++){
            cin >> classes[i][j];
        }
        sort(classes[i].begin(), classes[i].end());
    }
    
    priority_queue<Element, vector<Element>, Compare> minHeap;
    int currentMax = 0;
    
    for (int i = 0; i < n; i++){
        minHeap.push({classes[i][0], i, 0});
        currentMax = max(currentMax, classes[i][0]);
    }
    
    int ans = numeric_limits<int>::max();
    
    while (true) {
        Element curr = minHeap.top();
        minHeap.pop();
        
        ans = min(ans, currentMax - curr.value);
        
        if (curr.pos + 1 < s) {
            int nextVal = classes[curr.classIndex][curr.pos + 1];
            minHeap.push({nextVal, curr.classIndex, curr.pos + 1});
            currentMax = max(currentMax, nextVal);
        } else {
            break;
        }
    }
    
    cout << ans << "\n";
}