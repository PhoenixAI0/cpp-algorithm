#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> h(N + 1);
    for (int i = 1; i <= N; i++){
        cin >> h[i];
    }
    
    long long ans = 0;
    stack<int> st;

    for (int i = 1; i <= N; i++){
        while (!st.empty() && h[st.top()] < h[i]){
            int idx = st.top();
            st.pop();
            ans += (long long)(i - idx + 1);
        }
        if (!st.empty()){
            ans += (long long)(i - st.top() + 1);
        }
        st.push(i);
    }
    
    cout << ans << "\n";
}