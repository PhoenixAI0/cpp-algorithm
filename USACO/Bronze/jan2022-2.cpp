#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	int wins = 0;
	for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] > b[j]) wins++;
            if (a[i] < b[j]) wins--;
        }
    }
	return wins > 0;
}

bool solve(vector<int> A, vector<int> B) {
	for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            for (int c = 1; c <= 10; c++) {
                for (int d = 1; d <= 10; d++) {
                    vector<int> C = {a,b,c,d};
                    if (compare(A,B) && compare(B,C) && compare(C,A) || compare(B,A) && compare(C,B) && compare(A,C)) return true;
                }
            }
        }
    }
	return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        vector<int> a(4);
        vector<int> b(4);
        for (int i = 0; i < 4; i++) cin >> a[i];
        for (int i = 0; i < 4; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool success = solve(a, b);
        if (success) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}