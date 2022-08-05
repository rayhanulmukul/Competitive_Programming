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
#define dbg(...) cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#define ok tikkk
#else
#define pause(x) 
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(...) 
#define ok
#endif
const int N = 1e5+10;
vector<int>adj[N];
vector<int>vis(N);

int dfs(int a){
  //  dbg(a)
    vis[a] = 1;
    for(auto x: adj[a]){
        if(vis[x] == 0){
            if(dfs(x)) return 1;
        }else if(vis[x] == 1){
            return 1;
        }
    }
    vis[a] = 2;
    return 0;
}

void solvetc(int tt){
    in(n) inp(arr, n)
    rep(i, n+5){
        adj[i].clear();
        vis[i] = 0;
    }
    int rival = n-1;
    if(arr[0] <= arr[n-1]){
        adj[n-1].pb(0);
    }else{
        adj[0].pb(n-1);
    }
    for(int i = 1; i < n;i++){
        if(arr[i] > arr[i-1]){
            //ager ta coto
            int nx = rival +1;
            nx %= n;
            adj[nx].pb(rival);
            dbg(nx, rival)
            rival--;
        }else{
            int nx = rival +1;
            nx %= n;
            adj[rival].pb(nx);
            dbg(rival, nx);
            rival--;
        }
    }
    for(int i = 0; i <= n-1; i++){
        if(vis[i] == 0){
           // dbg(i);
            if(dfs(i)){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int32_t main()
{
    ios ;
    #ifdef DEBUG
    freopen("in", "r", stdin);
    #endif
    int nn = 1;
    cin >> nn;
    rep(i, nn) solvetc(i+1);
}