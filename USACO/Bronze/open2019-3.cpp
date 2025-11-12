#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    
    int n; cin >> n;
    vector<set<string>> subsets(n);
    map<string, set<int>> features_dict;

    for (int idx = 0; idx < n; ++idx) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            string feature; cin >> feature;
            subsets[idx].insert(feature);
            features_dict[feature].insert(idx);
        }
    }

    vector<string> features;
    for (const auto& pair : features_dict) {
        features.push_back(pair.first);
    }

    for (size_t i = 0; i < features.size(); ++i) {
        for (size_t j = i + 1; j < features.size(); ++j) {
            const string& f1 = features[i];
            const string& f2 = features[j];
            const set<int>& s1 = features_dict[f1];
            const set<int>& s2 = features_dict[f2];

            bool is_subset1 = includes(s2.begin(), s2.end(), s1.begin(), s1.end());
            bool is_subset2 = includes(s1.begin(), s1.end(), s2.begin(), s2.end());
            
            bool is_disjoint = false;
            if (s1.empty() || s2.empty()) {
                is_disjoint = true;
            } else {
                auto it1 = s1.begin();
                auto it2 = s2.begin();
                while (it1 != s1.end() && it2 != s2.end()) {
                    if (*it1 == *it2) {
                        break;
                    } else if (*it1 < *it2) {
                        ++it1;
                    } else {
                        ++it2;
                    }
                }
                is_disjoint = (it1 == s1.end() || it2 == s2.end());
            }

            if (!(is_subset1 || is_subset2 || is_disjoint)) {
                cout << "no" << "\n";
                return 0;
            }
        }
    }

    cout << "yes" << "\n";
}