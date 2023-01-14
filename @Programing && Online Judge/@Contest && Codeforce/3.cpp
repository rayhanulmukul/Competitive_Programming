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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = s[s.size()-1] - '0';
    if(x%2 == 0){
        cout << "NO" << en;
        return;
    }
    int y = 0, var;
    x = 0;
    int arr[n];
    int brr[n];

    for(int i = 0; i < n; i++){
        var = s[i] - '0';
        x += var;
        arr[i] = var;
    }
    for(int i = n; i < 2*n; i++){
        var = s[i] - '0';
        y += var;
        brr[i-n] = var;
    }
    if(x == y){
        cout << "NO" << en;
        return;
    }
    sort(arr, arr + n);
    sort(brr, brr + n);
    int c1 = 0, c = 0;
    for(int i = 0; i < n; i ++){
        if(arr[i] > brr[i]){
            c++;
        }
        else if(arr[i] < brr[i]){
            c1++;
        }
    }
    if(c == n || c1 == n){
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
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}