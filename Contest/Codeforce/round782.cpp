#include <bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
#define gap ' '
#define en '\n'
#define sz(x) (int(x.size()))
#define sor(x)  sort(x.begin(), x.end())

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

void solve(){
    int a, b;
    cin >> a >> b;
    if(a == 1 && b == 1) cout << "0" << en;
    else if(a == 1 && b >2) cout << -1 << en;
    else if(b == 1 && a >2) cout << -1 << en;
    //else if(abs(a-b) == 1) cout << 1 << en;
    else{
        int sum = a + b;
        int mi = min(a, b);
        int x = mi + (mi - 2);
        int ans = max(a, b) - mi;
        //cout << x;
        if(ans == 0) cout << x << en;
        else if(sum % 2 == 0) cout << x + ans*2 << en;
        else cout << x + (ans*2-1) << en;
 
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();}
    return 0;
}