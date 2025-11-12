#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

bool isOperator(const string &token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

double evaluatePrefix(const vector<string> &tokens, int &pos) {
    const string &token = tokens[pos++];
    
    if (isOperator(token)) {
        double leftValue  = evaluatePrefix(tokens, pos);
        double rightValue = evaluatePrefix(tokens, pos);
        
        if      (token == "+") return leftValue + rightValue;
        else if (token == "-") return leftValue - rightValue;
        else if (token == "*") return leftValue * rightValue;
        else if (token == "/") return leftValue / rightValue;
    }

    else {
        return stod(token);
    }
    return 0.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    vector<string> tokens;
    {
        istringstream iss(line);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
    }
    int pos = 0;
    double result = evaluatePrefix(tokens, pos);
    cout << fixed << setprecision(6) << result << endl;
}