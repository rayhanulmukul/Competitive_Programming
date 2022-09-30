#include <bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
//#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int(x.size()))
#define mem(a, b) memset(a, b, sizeof(a))
#define sor(x)  sort(x.begin(), x.end())
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;

vector < pair <ll, ll > > v[N];
bool vis[N];
vector < ll > ans;

ll dis[N];
ll mx = 0;

void dfs(ll node, ll dist){
    if(vis[node] == 1) return;
    ans.push_back(node); // somehow connected to node a
    vis[node] = 1;
    mx = max(mx, dist);
    dis[node] = dist;
    for(auto [u, w] : v[node]){
        dfs(u, dist + w);
    }
    return;
}
void solve(int tt){
    ll n; // n = node count, m = edge count
    cin >> n;
    mem(vis, 0); // vis[i] = 0
    for(int i = 0; i < n; i++){
        ll x, y, w;
        cin >> x >> y >> w; // input edges
        v[x].push_back({y, w});
        v[y].push_back({x, w});
    }

    dfs(0, 0);
    
    ll nxt_node;

    for(ll i = 0; i < n; i++){
        if(dis[i] == mx){
            nxt_node = i;
            break;
        }
    }
    for(ll i = 0; i < n; i++) vis[i] = 0;
    mx = 0;

    dfs(nxt_node, 0);

    cout << mx << en;
}
int32_t main(){
    #ifndef DEBUG
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}