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
    int n, x, ans = 0, m = 0, k = 0;
    cin >> n;
    string s;
    cin >> s;
    int arr[n];
    F0R(i, n){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(i+1 < n && s[i+1] == '1'){
                swap(arr[i], arr[i+1]);
            }
        }
        else if(i+1 < n && s[i] == '1' && s[i+1] == '1'){
            if(s[i] < s[i+1]) swap(arr[i], arr[i+1]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

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