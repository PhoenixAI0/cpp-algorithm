#include <bits/stdc++.h>
using namespace std;

int n, num = 0;
int a[15] = {0}, b[15] = {0};

int gcd(int a, int b) {
	int max = a > b ? a : b;
	int  min = a < b ? a : b;
	
	if (min == 0) return max;
	else return gcd(min, max % min);
}

int solve(int * a, int n) {
	if (n == 0)	return 0;
		
	int nb = 0;
	int c[15] = {0};
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!c[i] && gcd(a[i], a[j]) != 1 && !c[j]) {
				b[nb++] = a[j];
				c[j] = 1;
			}
        }
    }
	num++;
	solve(b, nb);
	return 0; 
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	solve(a, n);
	cout << num << "\n";
}