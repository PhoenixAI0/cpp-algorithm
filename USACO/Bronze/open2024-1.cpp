#include <bits/stdc++.h>
using namespace std;

void readInput(int& n, int& q, vector<string>& s) {
    cin >> n >> q;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
}

void assignGroups(const vector<string>& s, vector<int>& group, int& groupCount) {
    int n = s.size();
    group.assign(n, 0);
    groupCount = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == "or") {
            ++groupCount;
        } else if (i % 2 == 0) {
            group[i] = groupCount;
        }
    }
}

void calculateFalseIndices(const vector<string>& s, const vector<int>& group, vector<int>& firstFalse, vector<int>& lastFalse, int groupCount) {
    firstFalse.assign(groupCount + 1, INT_MAX);
    lastFalse.assign(groupCount + 1, -1);
    for (int i = 0; i < s.size(); i += 2) {
        int g = group[i];
        if (s[i] == "false") {
            firstFalse[g] = min(firstFalse[g], i);
            lastFalse[g] = i;
        }
    }
}

void calculateTrueGroups(const vector<int>& firstFalse, int groupCount, int& totalFirstTrue, int& totalLastTrue) {
    totalFirstTrue = INT_MAX;
    totalLastTrue = -1;
    for (int i = 0; i <= groupCount; ++i) {
        if (firstFalse[i] == INT_MAX) {
            if (totalFirstTrue == INT_MAX) {
                totalFirstTrue = i;
            }
            totalLastTrue = i;
        }
    }
}

void processQueries(int q, const vector<int>& group, const vector<int>& firstFalse, const vector<int>& lastFalse, int totalFirstTrue, int totalLastTrue) {
    while (q--) {
        int l, r;
        string t;
        cin >> l >> r >> t;
        --l; --r;

        int lGroup = group[l];
        int rGroup = group[r];

        if (totalFirstTrue < lGroup || totalLastTrue > rGroup) {
            cout << (t == "true" ? 'Y' : 'N');
            continue;
        }

        if (t == "true") {
            cout << ((firstFalse[lGroup] < l || lastFalse[rGroup] > r) ? 'N' : 'Y');
        } else {
            cout << 'Y';
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    vector<string> s;
    readInput(n, q, s);

    vector<int> group;
    int groupCount;
    assignGroups(s, group, groupCount);

    vector<int> firstFalse, lastFalse;
    calculateFalseIndices(s, group, firstFalse, lastFalse, groupCount);

    int totalFirstTrue, totalLastTrue;
    calculateTrueGroups(firstFalse, groupCount, totalFirstTrue, totalLastTrue);

    processQueries(q, group, firstFalse, lastFalse, totalFirstTrue, totalLastTrue);
}