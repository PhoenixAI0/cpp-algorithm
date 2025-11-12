#include <iostream>
#include <cstring>   
using namespace std;

static char str[8];   
static char perm[8];  
static bool used[8];  
static int n;         

void backtrack(int idx) {
    
    if (idx == n) {
        perm[idx] = '\0';
        cout << perm << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            perm[idx] = str[i];
            backtrack(idx + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> str;
    n = strlen(str);
    
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }
    
    backtrack(0);
}
