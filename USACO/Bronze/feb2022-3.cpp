#include <bits/stdc++.h>
using namespace std;

bool canSpell(const string &word, const vector<string> &blocks, vector<bool> &used_blocks, int index) {
    if (index == word.size()) {
        return true;
    }

    char letter = word[index];
    for (int i = 0; i < blocks.size(); ++i) {
        if (!used_blocks[i] && blocks[i].find(letter) != string::npos) {
            used_blocks[i] = true;
            if (canSpell(word, blocks, used_blocks, index + 1)) {
                return true;
            }
            used_blocks[i] = false;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> blocks(4);
    for (int i = 0; i < 4; ++i) {
        cin >> blocks[i];
    }

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    for (const string &word : words) {
        vector<bool> used_blocks(4, false);
        if (canSpell(word, blocks, used_blocks, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}