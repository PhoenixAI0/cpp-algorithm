#include <bits/stdc++.h>
using namespace std;

void sort3(vector<pair<string, int>>& vector) {
  for (int i = 1; i < vector.size(); i++) {
    int key = vector[i].second;
    int j = i - 1;
    while (j >=0 && key < vector[j].second) {
      vector[j + 1] = vector[j];
      --j;
    }
    vector[j + 1] = vector[i];
  }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<pair<string, int>> elderly;
    vector<pair<string, int>> others;
    for (int i = 0; i < n; i++) {
        if (a[i].second >= 60) {
            elderly.push_back(a[i]);
        } else {
            others.push_back(a[i]);
        }
    }
    sort3(elderly);
    reverse(elderly.begin(), elderly.end());

    for (int i = 0; i < elderly.size(); i++) {
        cout << elderly[i].first << "\n";
    }
    for (int i = 0; i < others.size(); i++) {
        cout << others[i].first << "\n";
    }
}