// #pragma GCC target("fpmath=sse,sse2") // off
// #pragma GCC target("fpmath=387") // on
#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<(int)b;i++)
#define FORr(i,a,b) for(int i =a;i>=(int)b;i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define print(arr)  for(auto a: arr) cout << a<< " "; cout << endl;
#define in(a) int a; cin >> a;
#define inp(arr,n) vector<int>arr(n); for(auto &a: arr) cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vi vector<int>
#define s second
#define mxheap priority_queue<int>
#define mnheap priority_queue<int, vector<int>, greater<int>>
#define mxheap2 priority_queue<pair<int,int>>
#define mnheap2 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
#define case cout << "Case "<< tt << ": ";
inline int uceil(int a,int b) {return (a % b ? a / b + 1 : a / b);}
#define pll pair<int, int>
#define set_bit(x, idx) x = x|(1LL<<idx)
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define endl "\n"
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define db long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)


#ifdef DEBUG
#include "tpc.hpp"
#define pause(x) thamm
#define ios
#define dbg(...) {cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);}
#define ok tikkk
#else
#define pause(x) 
#define ios {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define dbg(...) 
#define ok
#endif

struct Dsu{
    vector<ll>par, siz;
    void Init(ll n){
        par.resize(n+5);
        siz.resize(n+5,1);
        for(int i =0; i<= n; i++) par[i] = i;
    }
    ll Find(ll n){
        if(par[n] == n) return n;
        else return par[n] = Find(par[n]);
    }
    bool Check(ll a, ll b){
        a = Find(a); b = Find(b);
        if(a == b) return true;
        return false;
    }
    bool Union(ll a, ll b){
        a = Find(a); b = Find(b);
        if(a == b) return false;
        if(siz[a] > siz[b]) swap(a,b);
        par[a] = b;
        siz[b] += siz[a];
        return true;
    }
};

void solvetc(int tt){
    Dsu ashiq;
    ashiq.Init(500);
    int n = rng(1,8);
    cout << n << endl;
    rep(i, n){
        cout << rng(1,10) <<" ";
    }
    cout << endl;
    int nct= 0 ;
    while(nct < n-1){
        int a = rng(1,n);
        int b = rng(1,n);
        if(ashiq.Check(a,b)) continue;
        cout << a <<" " << b << " " << rng(-100,100) << endl;
        ashiq.Union(a,b);
        nct++;
    }
}

int32_t main()
{
    ios ;
    #ifdef DEBUG
    //freopen("in", "r", stdin);
    #endif
    int nn = 1;
    //cin >> nn;
    rep(i, nn) solvetc(i+1);
}
