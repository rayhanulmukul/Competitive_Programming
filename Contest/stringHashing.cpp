#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
#include<vector>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int)(x.size())
#define mem(a, b) memset(a, b, sizeof(a))
#define sor(x)  sort(x.begin(), x.end())

#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
//dbug(), watch(), output_run_time()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
#define R0F(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) R0F(i,0,a)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;

map <pair <int, int>, int> mp;
int power(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
void build(string &s, int mid){
    int n = s.size();
    int x = 1, y = 1;
    int bg1 = power(29, MOD-2);
    int bg2 = power(31, MOD-2);
    pair <int, int> hash = {0, 0};
    for(int i = 0; i < mid; i++){
        if(i > 0){
            x = (x*29)%MOD;
            y = (y*31)%MOD;
        }
        int num = s[i]-'a';
        hash.first += num*x; hash.first %= MOD;
        hash.second += num*y; hash.second %= MOD;
        //dbg(hash, s, mid);
    }
    //dbg(hash, s, mid);
    mp[hash] = 0;
    dbg(mp, hash, s, mid);
    for(int i = mid; i < n; i++){
        int num = s[i-mid]-'a';
        hash.first -= num; if(hash.first < 0) hash.first += MOD;
        hash.first *= bg1; hash.first %= MOD;
        hash.second -= num; if(hash.second < 0) hash.second += MOD;
        hash.second *= bg2; hash.second %= MOD;
        num = s[i]-'a';
        hash.first += num*x; hash.first %= MOD;
        hash.second += num*y; hash.second %= MOD;
        mp[hash] = i-mid+1;
    }
}
int check(string &s, int mid){
    int n = s.size();
    int x = 1, y = 1;
    int bg1 = power(29, MOD-2);
    int bg2 = power(31, MOD-2);
    pair <int, int> hash = {0, 0};
    for(int i = 0; i < mid; i++){
        if(i > 0){
            x = (x*29)%MOD;
            y = (y*31)%MOD;
        }
        int num = s[i]-'a';
        hash.first += num*x; hash.first %= MOD;
        hash.second += num*y; hash.second %= MOD;
        //dbg(hash, s, mid);
    }
    //dbg(mp);
    if(mp[hash] >= mid) return true;
    for(int i = mid; i < n; i++){
        int num = s[i-mid]-'a';
        hash.first -= num; if(hash.first < 0) hash.first += MOD;
        hash.first *= bg1; hash.first %= MOD;
        hash.second -= num; if(hash.second < 0) hash.second += MOD;
        hash.second *= bg2; hash.second %= MOD;
        num = s[i]-'a';
        hash.first += num*x; hash.first %= MOD;
        hash.second += num*y; hash.second %= MOD;
        if(mp[hash] > i) return true;
    }
    return false;
}
void solve(int tt){
    int n; cin >> n;
    string s;
    cin >> s;
    int l = 0, r = s.size()/2;
    int res = 0;
    while(l <= r){
        int mid = (l+r)/2;
        dbg(l, r, mid, res);
        mp.clear();
        build(s, mid);
        if(check(s, mid)){
            dbg(mid);
            res = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << res << endl;
}
int32_t main(){
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}