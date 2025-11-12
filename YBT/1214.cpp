#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool is_valid(const vector<int>& perm) {
    int n = perm.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (abs(i - j) == abs(perm[i] - perm[j])) {
                return false;
            }
        }
    }
    return true;
}

vector<string> generate_solutions() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<string> solutions;

    do {
        if (is_valid(nums)) {
            
            string solution = "";
            for (int num : nums) {
                solution += to_string(num);
            }
            solutions.push_back(solution);
        }
    } while (next_permutation(nums.begin(), nums.end()));

    
    sort(solutions.begin(), solutions.end());
    return solutions;
}

int main() {
    int n;
    cin >> n;

    vector<int> queries(n);
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    vector<string> all_solutions = generate_solutions();

    for (int query : queries) {
        cout << all_solutions[query - 1] << '\n';
    }
}
