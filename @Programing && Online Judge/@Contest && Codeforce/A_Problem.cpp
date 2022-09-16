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
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int(x.size()))
#define sor(x)  sort(x.begin(), x.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

void solve(int tt){
    int n, k, odd = 0, even = 0, ma = 0, sum = 0, mi = 0;
    cin >> n >> k;
    int arr[n];
    set <int> s;
    F0R(i, n){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for(auto& it:s){
        if(it%2 != 0) odd++;
        else even++;
    }
    //int s = 0;
    //s = odd + even;
    // int m = 0;
    ma = min(odd, even);
    mi = max(odd, even);
    sum = mi - ma;
    int ans2 = sum + ma;
    if(ans2 == k){
        cout << "YES" << en;
    }
    else cout << "NO" << en;
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