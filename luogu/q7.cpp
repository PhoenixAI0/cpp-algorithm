#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;
    
    int type;
    cin >> type;
    
    vector<set<int>> beats;
    int i = 0;
    int n = S.size();
    
    while (i < n) {
        if (S[i] == '(') {
            set<int> beat;
            i++;
            while (i < n && S[i] != ')') {
                if (S[i] == 'L') {
                    if (i + 1 < n && S[i + 1] == '\'') {
                        beat.insert(1);
                        i += 2;
                    } else {
                        beat.insert(0);
                        i += 1;
                    }
                } else if (S[i] == 'R') {
                    if (i + 1 < n && S[i + 1] == '\'') {
                        beat.insert(3);
                        i += 2;
                    } else {
                        beat.insert(2);
                        i += 1;
                    }
                } else {
                    i += 1;
                }
            }
            i++;
            beats.push_back(beat);
        } else {
            set<int> beat;
            if (S[i] == 'L') {
                if (i + 1 < n && S[i + 1] == '\'') {
                    beat.insert(1);
                    i += 2;
                } else {
                    beat.insert(0);
                    i += 1;
                }
            } else if (S[i] == 'R') {
                if (i + 1 < n && S[i + 1] == '\'') {
                    beat.insert(3);
                    i += 2;
                } else {
                    beat.insert(2);
                    i += 1;
                }
            } else {
                i += 1;
            }
            beats.push_back(beat);
        }
    }
    
    cout << beats.size() << "\n";
    
    if (type == 1) {
        int max_a = 0, max_b = 0, max_c = 0, max_d = 0;
        
        for (auto &beat : beats) {
            int current = 0;
            for (auto &beat : beats) {
                if (beat.find(0) != beat.end()) {
                    current += 1;
                    if (current > max_a) max_a = current;
                } else {
                    current = 0;
                }
            }
        }
        
        {
            int current = 0;
            for (auto &beat : beats) {
                if (beat.find(1) != beat.end()) {
                    current += 1;
                    if (current > max_b) max_b = current;
                } else {
                    current = 0;
                }
            }
        }
        
        {
            int current = 0;
            for (auto &beat : beats) {
                if (beat.find(2) != beat.end()) {
                    current += 1;
                    if (current > max_c) max_c = current;
                } else {
                    current = 0;
                }
            }
        }
        
        {
            int current = 0;
            for (auto &beat : beats) {
                if (beat.find(3) != beat.end()) {
                    current += 1;
                    if (current > max_d) max_d = current;
                } else {
                    current = 0;
                }
            }
        }
        
        cout << max_a << " " << max_b << " " << max_c << " " << max_d << "\n";
    }
}