#include <bits/stdc++.h>
using namespace std;

void sort3(vector<int>& vector) {
  for (int i = 1; i < vector.size(); i++) {
    int key = vector[i];
    int j = i - 1;
    while (j >=0 && key < vector[j]) {
      vector[j + 1] = vector[j];
      --j;
    }
    vector[j + 1] = key;
  }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < 10; i++) {
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }
    sort3(even);
    sort3(odd);

    for (int i = 0; i < odd.size() / 2; i++) {
        swap(odd[i], odd[odd.size() - 1 - i]);
    }
    for (int i = 0; i < odd.size(); i++) {
        cout << odd[i] << " ";
    }
    for (int i = 0; i < even.size(); i++) {
        cout << even[i] << " ";
    }
    cout << "\n";
}