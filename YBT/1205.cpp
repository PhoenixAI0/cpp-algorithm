#include <iostream>
#include <string>

void towerOfHanoi(int n, char source, char auxiliary, char target, std::string &output) {
    if (n == 1) {
        output.push_back(source);
        output.append("->1->");
        output.push_back(target);
        output.push_back('\n');
        return;
    }
    
    towerOfHanoi(n - 1, source, target, auxiliary, output);

    output.push_back(source);
    output.append("->");
    output += std::to_string(n);
    output.append("->");
    output.push_back(target);
    output.push_back('\n');

    towerOfHanoi(n - 1, auxiliary, source, target, output);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    char r1, r2, r3; 
    std::cin >> n >> r1 >> r2 >> r3;

    std::string output;
    output.reserve(1 << n);  

    towerOfHanoi(n, r1, r3, r2, output);

    std::cout << output;
}
