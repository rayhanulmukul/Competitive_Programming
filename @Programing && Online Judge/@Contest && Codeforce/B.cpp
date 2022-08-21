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
    string s, s1, s2; cin >> s;
    int x, ans = 0; cin >> x;
    string Hours, Minutes, sMi0, sMi1, sHo0, sHo1;
    int mi, ho, tem = 0;
    Hours = s.substr(0, 2);
    Minutes = s.substr(3, 2);
    mi = x%60;
    ho = x/60;
    
    //cout << sHo0<< " " << sHo1 << en;
    int tmint = 0, thour = 0, k = 1, y = 0;
    string FM0, FM1, FH0, FH1;
    if(Hours[0] == Minutes[1] && Hours[1] == Minutes[0]){
            ans++;
    }
    tmint = stoi(Minutes);
    thour = stoi(Hours);
    while(true){
        tem = 0;
        if(FH0 == FM1 && FH1 == FM0){
            ans++;
        }
        FH0 = "";
        FH1 = "";
        FM0 = "";
        FM1 = "";
        tmint += mi;
        thour += ho;
        if(tmint > 59){
            tmint -= 60;
            thour++;
            if(thour > 23){
                thour -= 24;
            }
        }
        if(thour > 23){
            thour -= 24;
        }
        if(tmint > 9){
            tem = tmint%10;
            y = tmint/10;
            FM0 += y + '0';
            FM1 += tem + '0';
        }else {
            tem = 0;
            FM0 += tem + '0';
            FM1 += tmint + '0';
        }
        if(thour > 9){
            tem = thour%10;
            y = thour/10;
            FH0 += y + '0';
            FH1 += tem + '0';
        }else{
            tem = 0;
            FH0 += tem + '0';
            FH1 += thour + '0';
        }
        if(FH0[0] == s[0] && FH1[0] == s[1] && FM0[0] == s[3] && FM1[0] == s[4]){
            cout << ans-1 << en;
            return;
        }
        // cout << FH0 << FH1 << ":" << FM0 << FM1 << en;
        // cout << thour << " : " << tmint << en;
        // k++;
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