#include <bits/stdc++.h>
using namespace std;

int a[10], b[10];
set<int> possible;

void search(int milk1, vector<int>& barn1, vector<int>& barn2, int day) {
    if (day == 4) {
        possible.insert(milk1);
        return;
    }
    
    if (day % 2 == 0) {
        // Moving from barn1 to barn2
        for (int i = 0; i < barn1.size(); i++) {
            int bucket = barn1[i];
            barn1.erase(barn1.begin() + i);
            barn2.push_back(bucket);
            search(milk1 - bucket, barn1, barn2, day + 1);
            barn2.pop_back();
            barn1.insert(barn1.begin() + i, bucket);
        }
    } else {
        // Moving from barn2 to barn1
        for (int i = 0; i < barn2.size(); i++) {
            int bucket = barn2[i];
            barn2.erase(barn2.begin() + i);
            barn1.push_back(bucket);
            search(milk1 + bucket, barn1, barn2, day + 1);
            barn1.pop_back();
            barn2.insert(barn2.begin() + i, bucket);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> b[i];
    }
    
    vector<int> barn1(a, a + 10);
    vector<int> barn2(b, b + 10);
    
    search(1000, barn1, barn2, 0);  // Start with 1000 in barn1
    cout << possible.size() << "\n";
    return 0;
}