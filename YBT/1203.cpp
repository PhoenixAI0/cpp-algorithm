#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    while (true) {
        if(!std::getline(cin, line)) {
            break; 
        }
        
        cout << line << "\n";
        
        string marking(line.size(), ' ');
        
        stack<int> st;
        
        for (int i = 0; i < (int)line.size(); i++) {
            if (line[i] == '(') {
                st.push(i);
            } else if (line[i] == ')') {
                if (!st.empty()) {
                    
                    st.pop();
                } else {
                    
                    marking[i] = '?';
                }
            }
        }
        
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            marking[idx] = '$';
        }
        
        cout << marking << "\n";
    }
}
