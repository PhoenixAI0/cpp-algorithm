#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calculateTime(int targetDistance) {
  int minimumSpeed;
  cin >> minimumSpeed;
  int leftTravel = 0;
  int rightTravel = 0;
  int totalDuration = 0;
  for(int currentSpeed = 1;; currentSpeed++) {
    leftTravel += currentSpeed;
    totalDuration++;
    if(leftTravel + rightTravel >= targetDistance) return totalDuration;
    if(currentSpeed >= minimumSpeed) {
      rightTravel += currentSpeed;
      totalDuration++;
      if(leftTravel + rightTravel >= targetDistance) return totalDuration;
    }
  }
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll K;  
    int N;
    cin >> K >> N;
    
    while(N--) {
        cout << calculateTime(K) << "\n";
    }
}