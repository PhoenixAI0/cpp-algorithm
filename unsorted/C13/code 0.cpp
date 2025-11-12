#include <bits/stdc++.h>
#include <sstream>
using namespace std;

vector<string> qSort(vector<string> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    string pivot = arr[0];
    vector<string> left, right;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }
    vector<string> sortedLeft = qSort(left);
    vector<string> sortedRight = qSort(right);
    vector<string> sorted;
    sorted.reserve(arr.size());
    sorted.insert(sorted.end(), sortedLeft.begin(), sortedLeft.end());
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), sortedRight.begin(), sortedRight.end());
    return sorted;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    getline(cin, input);

    set<string> uniqueWords;
    istringstream iss(input);
    string word;

    while (iss >> word) {
        uniqueWords.insert(word);
    }

    vector<string> words(uniqueWords.begin(), uniqueWords.end());
    vector<string> sorted = qSort(words);
    for (const auto& str : sorted) {
        cout << str << "\n";
    }
}