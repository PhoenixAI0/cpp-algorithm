#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> missiles; 
    int height;
    while (cin >> height) {
        missiles.push_back(height);
    }

    vector<int> ends;
    for (int h : missiles) {
        bool placed = false;
        for (int &end : ends) {
            if (end >= h) {
                end = h;
                placed = true;
                break;
            }
        }
        if (!placed) {
            ends.push_back(h);
        }
    }
    std::cout << ends.size() << '\n';
}