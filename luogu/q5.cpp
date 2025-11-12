#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 生成一行的字符数组
string generateRow(int i, int m, int triangleWidth) {
    string row(m, '.'); // 初始化一行，全部为 '.'
    // 设置三角形部分
    for (int j = m - triangleWidth; j < m; ++j) {
        row[j] = '#';
    }
    return row;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int upperHeight = (n - k) / 2;
    int lowerHeight = n - upperHeight - k;

    for (int i = 1; i <= n; ++i) {
        string row;
        if (i <= upperHeight) {
            int triangleWidth = i;
            row = generateRow(i, m, triangleWidth);
        } else if (i <= upperHeight + k) {
            int triangleWidth = min(i - upperHeight, k - (i - upperHeight - 1));
            row = generateRow(i, m, triangleWidth);
            // 设置横杠部分
            row[0] = '#';
        } else {
            int triangleWidth = n - i + 1;
            row = generateRow(i, m, triangleWidth);
        }
        cout << row << endl;
    }

    return 0;
}