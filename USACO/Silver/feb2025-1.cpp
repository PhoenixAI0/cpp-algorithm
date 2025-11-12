#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> a) {
    int n = a.size();
    vector<int> s(n + 1, INT_MIN);
    for (int i = n - 1; i >= 0; --i) {
        s[i] = max(a[i], s[i + 1]);
    }
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= s[i + 1]) {
            b.push_back(a[i]);
        }
    }
    return b;
}

vector<int> g(int k, int j, vector<int> a, int n) {
    vector<int> a_new;
    a_new.reserve(n);
    for (int i = 0; i < j; ++i) {
        a_new.push_back(a[i]);
    }
    a_new.push_back(a[k]);
    for (int i = j; i < k; ++i) {
        a_new.push_back(a[i]);
    }
    for (int i = k + 1; i < n; ++i) {
        a_new.push_back(a[i]);
    }
    return a_new;
}

vector<int> h(int n, vector<int> a) {
    vector<int> s(n, INT_MIN);
    if (n > 0) {
        s[0] = a[0];
        for (int i = 1; i < n; ++i) {
            s[i] = max(s[i - 1], a[i]);
        }
    }

    vector<int> b = f(a);
    vector<int> c = b;

    for (int k = 0; k < n; ++k) {
        int m = (k > 0) ? s[k - 1] : INT_MIN;
        if (m < a[k]) {
            vector<int> a_new = {a[k]};
            for (int i = 0; i < k; ++i) {
                a_new.push_back(a[i]);
            }
            for (int i = k + 1; i < n; ++i) {
                a_new.push_back(a[i]);
            }
            vector<int> b_new = f(a_new);
            if (b_new > c) {
                c = b_new;
            }
        } else {
            int j = k - 1;
            while (j >= 0 && a[j] < a[k]) {
                --j;
            }
            if (j >= 0) {
                int j_prime = j + 1;
                if (j_prime < k) {
                    vector<int> a_new = g(k, j_prime, a, n);
                    vector<int> b_new = f(a_new);
                    if (b_new > c) {
                        c = b_new;
                    }
                }
            }
        }
    }

    return c;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        vector<int> b = h(n, a);
        for (size_t j = 0; j < b.size(); ++j) {
            if (j > 0) cout << " ";
            cout << b[j];
        }
        cout << "\n";
    }
}