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
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;

void solve(int tt){
    int n;
    cin >> n;
    int ans = 0, three = 0, two = 0, one = 0;
    int arr[n];
    F0R(i, n){
        cin >> arr[i];
        if(arr[i] == 4) ans++;
        else if(arr[i] == 3) three++;
        else if(arr[i] == 2) two++;
        else one++;
    }
    if(one >= three){
        ans+= three;
        one -= three;
    }
    else{
        ans += one;
        ans += (three-one);
        one = 0;
    }
    ans += two/2;
    two %= 2;
    ans += one/4;
    one %= 4;

    int x = one/2;
    if(x >= two){
        ans += two;
        x -= two;
        if(one % 2 != 0) x++;
        if(x > 0) ans++;
    }
    else{
        ans += x;
        two -= x;
        if(two > 0) ans++;
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