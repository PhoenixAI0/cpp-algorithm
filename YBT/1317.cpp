#include <bits/stdc++.h>

void search(int n, int r, int start, std::vector<int>& current) {
    if (current.size() == r) {
        for (int i : current) {
            std::cout << "  " << i;
        }
        std::cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        current.push_back(i);
        search(n, r, i + 1, current);
        current.pop_back();
    }
}

int main() {
    int n, r;
    std::cin >> n >> r;
    std::vector<int> current;
    search(n, r, 1, current);
}
