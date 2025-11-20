#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;

void f1(int x) {
    cout << x << " ";
    if (a[x].first != 0) f1(a[x].first);
    if (a[x].second != 0) f1(a[x].second);
    
}
void f2(int x) {
    if (a[x].first != 0) f2(a[x].first);
    cout << x << " ";
    if (a[x].second != 0) f2(a[x].second);
    
}
void f3(int x) {
    if (a[x].first != 0) f3(a[x].first);
    if (a[x].second != 0) f3(a[x].second);
    cout << x << " ";
    
}

int main() {
    int n; cin >> n;
    a.resize(n+1);
    for (int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    f1(1); cout << "\n";
    f2(1); cout << "\n";
    f3(1); cout << "\n";
}
