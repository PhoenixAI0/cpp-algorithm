#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int mn = 0, mx = 0;

	int curIdx = 0;
	while (curIdx < n) {
		if (s[curIdx] == 'F') {
			curIdx++;
			continue;
		}

		int nextIdx = curIdx + 1;
		while (nextIdx < n && s[nextIdx] == 'F') nextIdx++;
		if (nextIdx == n) break;

		int num_F = nextIdx - curIdx - 1;

		if (s[nextIdx] == s[curIdx]) {
			int length = num_F + 2;

			if (length % 2 == 0) {
				mn += 1;
			} else {
				mn += 0;
			}

			mx += length - 1;
		} else {
			int length = num_F + 2;

			if (length % 2 == 0) {
				mn += 0;
			} else {
				mn += 1;
			}

			mx += length - 2;
		}

		curIdx = nextIdx;
	}

	int num_beginning_F = 0;
	while (num_beginning_F < n && s[num_beginning_F] == 'F') num_beginning_F++;
	int num_ending_F = 0;
	while (num_ending_F < n && s[n - 1 - num_ending_F] == 'F') num_ending_F++;

	if (num_beginning_F == n) {
		mn = 0;
		mx = n - 1;
	} else {
		mx += num_beginning_F;
		mx += num_ending_F;
	}

	vector<int> possible_levels;
	if (num_beginning_F == 0 && num_ending_F == 0) {
		assert((mx - mn) % 2 == 0);
		for (int i = mn; i <= mx; i += 2) possible_levels.push_back(i);
	} else {
		for (int i = mn; i <= mx; i++) possible_levels.push_back(i);
	}

	cout << possible_levels.size() << endl;
	for (int i : possible_levels) { cout << i << endl; }
}