#include <bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
#define int ll
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
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
#define R0F(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) R0F(i,0,a)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;

void solve(int tt){
    int n, ma = 0;
    cin >> n;
    map <int,int> m;
    vector <pair<int,int> > v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m[x]++;
    }
    for(auto it:m){
        //cout << it.first << gap << it.second << en;
       v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end());
    int ans = v[0].second;
    for(int i = 0; i < v.size()-1; i++){
        int x = v[i+1].first - v[i].second;
        if(v[i].first == v[i+1].first-v[i].first]){
            ans += v[i+1].second;
        }

    }
    cout << ans << en;
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