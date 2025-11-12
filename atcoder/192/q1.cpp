#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    vector<int> A(N);
    bool allOne = true;
    bool allZero = true;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] == 0) allOne = false;
        if(A[i] == 1) allZero = false;
    }

    if(allOne){
        cout << "Yes\n";
        return 0;
    }
    if(allZero && (N % 2 == 1)){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}