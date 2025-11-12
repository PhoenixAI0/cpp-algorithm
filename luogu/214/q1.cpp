#include <iostream>
using namespace std;

int main() {
    long long V_egg, V_milk, V_tart;
    cin >> V_egg >> V_milk >> V_tart;
    
    long long e, m, t;
    cin >> e >> m >> t;
    
    long long total_volume = e * V_egg + m * V_milk;
    
    long long num_tarts = (total_volume + V_tart - 1) / V_tart;
    
    cout << (num_tarts + t - 1) / t;
}