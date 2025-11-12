#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> in_map;
string preorder, inorder;

void build_tree(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end) return;
    
    char root = preorder[pre_start];
    int root_idx = in_map[root];
    int left_size = root_idx - in_start;
    
    build_tree(pre_start + 1, pre_start + left_size, in_start, root_idx - 1);
    build_tree(pre_start + left_size + 1, pre_end, root_idx + 1, in_end);
    
    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> inorder >> preorder;
    
    for (int i = 0; i < inorder.size(); i++) {
        in_map[inorder[i]] = i;
    }
    
    build_tree(0, preorder.size() - 1, 0, inorder.size() - 1);
    cout << "\n";
}