#include <bits/stdc++.h>
using namespace std;

long long pw2(int x){return (1LL << x) - 1;} // smallest number with popcount x

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        long long M;int K;cin>>M>>K;
        if(K==1){
            // Need all popcounts = 1; sum must be M
            // That means we just split M into its set bits if possible
            // Count bits of M
            int c = __builtin_popcountll(M);
            if(c>100){cout<<"-1\n";continue;}
            cout<<c<<"\n";
            // Print each set bit as a separate power of two
            for(int i=0;i<60;i++){
                if(M & (1LL<<i)) cout<<(1LL<<i)<<" ";
            }
            cout<<"\n";
            continue;
        }
        // Factor K into primes up to 29
        // If at any point we get a factor above 29 (except possibly 31 => no sol), we stop
        int ktmp=K;
        map<int,int> f; 
        vector<int> primes={2,3,5,7,11,13,17,19,23,29};
        for(int p: primes){
            while(ktmp%p==0){
                f[p]++;
                ktmp/=p;
            }
        }
        // if something > 1 remains, it must be prime >29; if it's 31 => no solution, or any bigger => no solution
        if(ktmp>1){
            // If that leftover is 31 => no solution (can't have popcount=31 <=1e9), or anything bigger => no solution
            cout<<"-1\n";
            continue;
        }
        // Now we have a factor map f containing only primes in {2,3,5,7,11,13,17,19,23,29}
        // base_sum = sum of e copies of (2^p -1)
        // base_count = total e
        long long base_sum=0; 
        int base_count=0;
        bool fail=false;
        for(auto &pp: f){
            int p=pp.first, e=pp.second;
            long long val = pw2(p);  // (1<<p)-1
            // check if val <= 10^9? Actually if val> M it might fail anyway
            // just do it
            long long add = val*(long long)e;
            if(add>1e10) {fail=true;break;} // just to be safe
            base_sum += add;
            base_count += e;
        }
        if(fail || base_sum>M){
            cout<<"-1\n";
            continue;
        }
        // Now we fill remainder = M - base_sum with powers of two (popcount=1)
        long long R = M - base_sum;
        // total elements = base_count + popcount(R)
        int cR = __builtin_popcountll(R);
        if(base_count + cR>100){
            cout<<"-1\n";
            continue;
        }
        // Construct answer
        cout<<(base_count + cR)<<"\n";
        // Print all the (1<<p)-1 elements
        for(auto &pp: f){
            int p=pp.first, e=pp.second;
            long long val = pw2(p);
            while(e--) cout<<val<<" ";
        }
        // Print the powers of two for R
        for(int i=0;i<60;i++){
            if(R & (1LL<<i)) cout<<(1LL<<i)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}