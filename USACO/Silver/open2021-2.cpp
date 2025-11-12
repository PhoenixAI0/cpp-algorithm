#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// A linear expression for a variable: value = base + coeff * t.
struct Lin {
    ll base;
    int coeff; // can be -1, 0, or 1.
    bool free; // true if this variable is still free (depends on t)
};

// Evaluate a Lin expression at parameter t.
ll evalLin(const Lin &L, ll t) {
    return L.base + (ll)L.coeff * t;
}

// A triple (A,B,C).
struct Triple {
    ll A, B, C;
};

struct TripleHash {
    size_t operator()(const Triple &tr) const {
        auto h1 = std::hash<ll>()(tr.A);
        auto h2 = std::hash<ll>()(tr.B);
        auto h3 = std::hash<ll>()(tr.C);
        return ((h1 * 31 + h2) * 31 + h3);
    }
};

bool operator==(const Triple &a, const Triple &b) {
    return a.A == b.A && a.B == b.B && a.C == b.C;
}

// We use a modified elimination routine that processes the provided equations.
// Each equation comes with a "role" (an integer in {0,1,2,3,4,5,6}) meaning:
//
//  0: A = value
//  1: B = value
//  2: C = value
//  3: A+B = value
//  4: A+C = value
//  5: B+C = value
//  6: A+B+C = value
//
// The injection is given as a vector eq of length 7 (with -1 meaning “not provided”)
// and a template mapping vector tmpl of length 7, so that for each position i,
// the equation (if provided) is:  role = tmpl[i] and value = eq[i].
 
vector<Triple> solveInjection(const vector<ll>& eq, const vector<int>& tmpl) {
    // We'll process the equations in the following order: roles 0,1,2 then 3,4,5 then 6.
    Lin A_lin = {0, 0, true};
    Lin B_lin = {0, 0, true};
    Lin C_lin = {0, 0, true};
    bool freeAssigned = false; // whether we've already introduced a free parameter.

    // Helper lambda: process a given equation with role r and given value.
    auto processEquation = [&](int r, ll val) -> bool {
        if(r == 0) { // A = val
            if(!A_lin.free && A_lin.coeff == 0 && A_lin.base != val)
                return false;
            A_lin.base = val; A_lin.coeff = 0; A_lin.free = false;
        } else if(r == 1) { // B = val
            if(!B_lin.free && B_lin.coeff == 0 && B_lin.base != val)
                return false;
            B_lin.base = val; B_lin.coeff = 0; B_lin.free = false;
        } else if(r == 2) { // C = val
            if(!C_lin.free && C_lin.coeff == 0 && C_lin.base != val)
                return false;
            C_lin.base = val; C_lin.coeff = 0; C_lin.free = false;
        } else if(r == 3) { // A+B = val
            if(!A_lin.free && !B_lin.free) {
                if(A_lin.base + B_lin.base != val)
                    return false;
            } else if(!A_lin.free && B_lin.free) {
                B_lin.base = val - A_lin.base;
                B_lin.coeff = 0; B_lin.free = false;
            } else if(A_lin.free && !B_lin.free) {
                A_lin.base = val - B_lin.base;
                A_lin.coeff = 0; A_lin.free = false;
            } else {
                // Both free.
                // Choose A = t and B = val - t.
                A_lin.base = 0; A_lin.coeff = 1; A_lin.free = true;
                B_lin.base = val; B_lin.coeff = -1; B_lin.free = true;
                freeAssigned = true;
            }
        } else if(r == 4) { // A+C = val
            if(!A_lin.free && !C_lin.free) {
                if(A_lin.base + C_lin.base != val)
                    return false;
            } else if(!A_lin.free && C_lin.free) {
                C_lin.base = val - A_lin.base;
                C_lin.coeff = 0; C_lin.free = false;
            } else if(A_lin.free && !C_lin.free) {
                A_lin.base = val - C_lin.base;
                A_lin.coeff = 0; A_lin.free = false;
            } else {
                if(!freeAssigned){
                    A_lin.base = 0; A_lin.coeff = 1; A_lin.free = true;
                    C_lin.base = val; C_lin.coeff = -1; C_lin.free = true;
                    freeAssigned = true;
                } else {
                    C_lin.base = val - A_lin.base;
                    C_lin.coeff = -A_lin.coeff; C_lin.free = true;
                }
            }
        } else if(r == 5) { // B+C = val
            if(!B_lin.free && !C_lin.free) {
                if(B_lin.base + C_lin.base != val)
                    return false;
            } else if(!B_lin.free && C_lin.free) {
                C_lin.base = val - B_lin.base;
                C_lin.coeff = 0; C_lin.free = false;
            } else if(B_lin.free && !C_lin.free) {
                B_lin.base = val - C_lin.base;
                B_lin.coeff = 0; B_lin.free = false;
            } else {
                if(!freeAssigned){
                    B_lin.base = 0; B_lin.coeff = 1; B_lin.free = true;
                    C_lin.base = val; C_lin.coeff = -1; C_lin.free = true;
                    freeAssigned = true;
                } else {
                    C_lin.base = val - B_lin.base;
                    C_lin.coeff = -B_lin.coeff; C_lin.free = true;
                }
            }
        } else if(r == 6) { // A+B+C = val
            bool aFree = A_lin.free, bFree = B_lin.free, cFree = C_lin.free;
            if(!aFree && !bFree && !cFree) {
                if(A_lin.base + B_lin.base + C_lin.base != val)
                    return false;
            } else if(!aFree && !bFree && cFree) {
                C_lin.base = val - A_lin.base - B_lin.base;
                C_lin.coeff = 0; C_lin.free = false;
            } else if(!aFree && bFree && !cFree) {
                B_lin.base = val - A_lin.base - C_lin.base;
                B_lin.coeff = 0; B_lin.free = false;
            } else if(aFree && !bFree && !cFree) {
                A_lin.base = val - B_lin.base - C_lin.base;
                A_lin.coeff = 0; A_lin.free = false;
            } else if(aFree && bFree && cFree) {
                // Would be 2 free parameters; skip.
                return false;
            } else {
                if(aFree && bFree && !cFree){
                    return false;
                } else if(aFree && !bFree && cFree){
                    A_lin.base = val - B_lin.base - C_lin.base;
                    A_lin.coeff = 0; A_lin.free = false;
                } else if(!aFree && bFree && cFree){
                    B_lin.base = val - A_lin.base - C_lin.base;
                    B_lin.coeff = 0; B_lin.free = false;
                }
            }
        }
        return true;
    };

    // Process equations in the order: roles 0, then 1, then 2, then 3,4,5 then 6.
    for (int r = 0; r <= 6; r++) {
        for (int i = 0; i < 7; i++) {
            if(tmpl[i] == r && eq[i] != -1) {
                if(!processEquation(r, eq[i]))
                    return {};
            }
        }
    }
    
    vector<Triple> sol;
    // If all variables are determined:
    if(!A_lin.free && !B_lin.free && !C_lin.free) {
        ll A_val = A_lin.base, B_val = B_lin.base, C_val = C_lin.base;
        if(A_val > 0 && B_val > 0 && C_val > 0 && A_val <= B_val && B_val <= C_val)
            sol.push_back({A_val, B_val, C_val});
        return sol;
    }
    
    // If any variable is still free but has no coefficient, force a coefficient.
    if(A_lin.free && A_lin.coeff == 0){ A_lin.coeff = 1; freeAssigned = true; }
    if(B_lin.free && B_lin.coeff == 0){ B_lin.coeff = 1; freeAssigned = true; }
    if(C_lin.free && C_lin.coeff == 0){ C_lin.coeff = 1; freeAssigned = true; }
    
    // Bound t so that A, B, C > 0 and A <= B <= C.
    ll lowT = -1000000000000000000LL, highT = 1000000000000000000LL;
    auto updateBound = [&](ll L, ll R) {
        lowT = max(lowT, L);
        highT = min(highT, R);
    };
    auto boundForPos = [&](const Lin &X) {
        if(X.coeff == 0){
            if(X.base <= 0) updateBound(1, 0);
            return;
        }
        if(X.coeff > 0){
            ll bound = -X.base + 1; // t >= -X.base+1
            updateBound(bound, highT);
        } else {
            updateBound(lowT, X.base - 1);
        }
    };
    boundForPos(A_lin); boundForPos(B_lin); boundForPos(C_lin);
    
    auto boundForOrder = [&](const Lin &X, const Lin &Y) {
        int dCoeff = Y.coeff - X.coeff;
        ll dBase = Y.base - X.base;
        if(dCoeff == 0){
            if(dBase < 0) updateBound(1, 0);
            return;
        }
        if(dCoeff > 0){
            double tmp = - (double)dBase / dCoeff;
            ll need = (ll)ceil(tmp);
            updateBound(need, highT);
        } else {
            double tmp = - (double)dBase / dCoeff;
            ll need = (ll)floor(tmp);
            updateBound(lowT, need);
        }
    };
    boundForOrder(A_lin, B_lin);
    boundForOrder(B_lin, C_lin);
    
    if(lowT > highT) return {};
    if(highT - lowT > 1000000) return {}; // safeguard
    
    for(ll t = lowT; t <= highT; t++){
        ll A_val = evalLin(A_lin, t);
        ll B_val = evalLin(B_lin, t);
        ll C_val = evalLin(C_lin, t);
        if(A_val <= 0 || B_val <= 0 || C_val <= 0) continue;
        if(A_val > B_val || B_val > C_val) continue;
        sol.push_back({A_val, B_val, C_val});
    }
    return sol;
}

 
// Main: For each test case, we try injections for both templates.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    
    // Define two templates.
    // Template 1: Sorted order is A, B, A+B, C, A+C, B+C, A+B+C (requires A+B < C)
    vector<int> tmpl1 = {0, 1, 3, 2, 4, 5, 6};
    // Template 2: Sorted order is A, B, C, A+B, A+C, B+C, A+B+C (requires A+B > C)
    vector<int> tmpl2 = {0, 1, 2, 3, 4, 5, 6};
    
    for(int tc = 0; tc < T; tc++){
        int N; cin >> N;
        vector<ll> S(N);
        for (int i = 0; i < N; i++){
            cin >> S[i];
        }
        sort(S.begin(), S.end());
        
        // We'll collect solutions from both templates.
        unordered_set<Triple, TripleHash> solSet;
        
        // We iterate over all injections: choose positions in [0,6] of size N.
        vector<int> comb;
        function<void(int,int, const vector<int>&)> rec = [&](int start, int left, const vector<int>& tmpl) {
            if(left == 0){
                vector<ll> eq(7, -1);
                // Assign S's values in order to the positions in the chosen combination.
                // The positions here refer to indices in the template order.
                // The injection means: for each j from 0 to N-1, set eq[comb[j]] = S[j].
                for (int i = 0; i < (int)comb.size(); i++){
                    eq[comb[i]] = S[i];
                }
                vector<Triple> sols = solveInjection(eq, tmpl);
                for(auto &tr: sols) {
                    // Now check the template-specific extra condition.
                    if(tmpl == tmpl1) { // Template 1 requires A+B < C.
                        if(tr.A + tr.B >= tr.C) continue;
                    } else { // Template 2 requires A+B > C.
                        if(tr.A + tr.B <= tr.C) continue;
                    }
                    solSet.insert(tr);
                }
                return;
            }
            for (int i = start; i < 7; i++){
                comb.push_back(i);
                rec(i+1, left-1, tmpl);
                comb.pop_back();
            }
        };
        
        // For both templates:
        rec(0, N, tmpl1);
        comb.clear();
        rec(0, N, tmpl2);
        
        cout << solSet.size() << "\n";
    }
    return 0;
}