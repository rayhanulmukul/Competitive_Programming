/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيمِ*/
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define ft front()
#define bk back()
#define pi 2*acos(0.0)
#define gap ' '
#define en '\n'
#define endl en
#define mem(a, b) memset(a, b, sizeof(a))
#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

const int N = 1e7;
vector<bool> is_prime(N + 1, true);
vector <int> primes;
vector <int> soluton(N + 1, 0);
vector<int> generatePrimes(int N){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
void preCal() {
    vector <int> freq(N, 0);
    for(int i = 0; i < primes.size(); i++){
        freq[primes[i]] = 1;
    }
    soluton[5] = 2;
    for(int i = 6; i <= 1e7; i++){
        if(freq[i] == 1){
            int diff = i - 2;
            if(freq[diff] == 1){
                soluton[i] = soluton[i - 1] + 1;
            }
            else{
                soluton[i] = soluton[i - 1];
            }
        }
        else{
            soluton[i] = soluton[i - 1];
        }
    }
}
void solve(int tt){
    int n;
    cin >> n;
    cout << "Case #" << tt << ": " << soluton[n] << endl;
}
int32_t main(){
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int t = 1;
    cin >> t;
    generatePrimes(N);
    preCal();
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}