#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
vector<int> ans;
bool found = false;
void search(vector<int>& remaining) {
    if (remaining.empty() && count(primes.begin(), primes.end(), ans[0] + ans.back())) {
        for (auto& number : ans) {
            cout << number << " ";
        }
        cout << "\n";
        found = true;
        return;
    }
    if (!found) {
        for (size_t i = 0; i < remaining.size(); i++) {
            int number = remaining[i];
            if (count(primes.begin(), primes.end(), number + ans.back())) {
                ans.push_back(number);
                remaining.erase(remaining.begin() + i);

                search(remaining);

                remaining.insert(remaining.begin() + i, number);
                ans.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> remaining;
    for (int i = 2; i <= n; i++) {
        remaining.push_back(i);
    }

    ans.push_back(1);
    search(remaining);
}