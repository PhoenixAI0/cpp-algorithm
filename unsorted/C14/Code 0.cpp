#include <bits/stdc++.h>
using namespace std;

void msort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    msort(arr, l, mid);
    msort(arr, mid + 1, r);
    
    int i = l, j = mid + 1;
    vector<int> tempArr(r - l + 1);

    for (int k = 0; k < tempArr.size(); k++) {
        if (i > mid) {
            tempArr[k] = arr[j++];
        } else if (j > r) {
            tempArr[k] = arr[i++];
        } else if (arr[i] < arr[j]) {
            tempArr[k] = arr[i++];
        } else {
            tempArr[k] = arr[j++];
        }
    }
    
    for (int k = 0; k < tempArr.size(); k++) {
        arr[l + k] = tempArr[k];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    msort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
