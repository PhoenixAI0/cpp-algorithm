#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
int quote[100005];
int N, L;
bool check(int h){
	int cnt = 0;
	int count_1 = 0;
	int count_2 = 0;
	for (int i = 1; i <= N; i++){ 
		if (quote[i] >= h){
			count_1++;
		}
		if (quote[i] == h - 1){
			count_2++;
		} 
	}
	if (count_1 >= h)return true;
	if (h - count_1 <= L && count_2 >= h - count_1)return true;
	return false;
} 
int main(){ 
	cin >> N >> L;
	for(int i = 1; i <= N; i++){
		cin >> quote[i];
	} 
	sort(quote + 1, quote + N + 1);
	int l = 0, r = N;
	while(l <= r){
		int mid = (l + r) / 2;
		if (check(mid))l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
}