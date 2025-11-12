#include <bits/stdc++.h>
using namespace std;

vector<int> computePrefix(const string &s) {
    int n = s.size();
    vector<int> ans(n+1,0);
    stack<char> st;
    int strokes = 0;
    for (int i = 1; i <= n; i++){
        char c = s[i-1];
        while (!st.empty() && st.top() > c) {
            st.pop();
            strokes++;
        }
        if (st.empty() || st.top() < c) {
            st.push(c);
        }
        ans[i] = strokes + st.size();
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    string fence;
    cin >> fence;

    vector<int> left = computePrefix(fence);
    string rev = fence;
    reverse(rev.begin(), rev.end());
    vector<int> rPrefix = computePrefix(rev);
    vector<int> right(N+2, 0);
    for (int i = 1; i <= N; i++){
        right[i] = rPrefix[N - i + 1];
    }
    right[N+1] = 0;

    for (int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        int ans = left[a - 1] + right[b + 1];
        cout << ans << "\n";
    }
}