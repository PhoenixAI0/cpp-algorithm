#include <bits/stdc++.h>
using namespace std;

void msort(vector<tuple<int, int, int>>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    msort(arr, l, mid);
    msort(arr, mid + 1, r);
    
    int i = l, j = mid + 1;
    vector<tuple<int, int, int>> tempArr(r - l + 1);
    int k = 0;
    
    while (i <= mid && j <= r) {
        if (get<0>(arr[i]) > get<0>(arr[j])) {
            tempArr[k++] = arr[i++];
        } else if (get<0>(arr[i]) < get<0>(arr[j])) {
            tempArr[k++] = arr[j++];
        } else if (get<1>(arr[i]) > get<1>(arr[j])) {
            tempArr[k++] = arr[i++];
        } else if (get<1>(arr[i]) < get<1>(arr[j])) {
            tempArr[k++] = arr[j++];
        } else if (get<2>(arr[i]) > get<2>(arr[j])) {
            tempArr[k++] = arr[j++];
        } else {
            tempArr[k++] = arr[i++];
        }
    }
    
    while (i <= mid) tempArr[k++] = arr[i++];
    while (j <= r) tempArr[k++] = arr[j++];
    
    for (int p = 0; p < k; p++) {
        arr[l + p] = tempArr[p];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int>> arr(n);
    
    for (int i = 0; i < n; i++) {
        int chinese, math, english;
        cin >> chinese >> math >> english;
        arr[i] = make_tuple(chinese + math + english, chinese, i + 1);
    }
    
    msort(arr, 0, n - 1);
    
    for (int i = 0; i < 5 && i < n; i++) {
        cout << get<2>(arr[i]) << " " << get<0>(arr[i]) << endl;
    }
}
