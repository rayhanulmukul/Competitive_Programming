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
    int n, x;
    cin >> n;
    int one = 0, two = 0, first = 0,second = 0, k, l;
    FOR(i, n){
        cin >> x;
        if(x < 0){
            two += x;
            if(second == 0) second = abs(x);
            k = x;
        }
        else{one += x;
            if(first == 0) first = x;
            k = x;
        }
    }
    if(one == abs(two)){
         if(first == second){
            if(k > 0) cout << "second" << en;
            else cout << "first" << en;
        }
        else if(first > second) cout << "first" << en;
        else cout << "second" << en;
    }
    else if(one > abs(two)){
        cout << "first" << en;
    }
    else cout << "second" << en;
    
   // cout << one << " " << abs(two) << en;
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