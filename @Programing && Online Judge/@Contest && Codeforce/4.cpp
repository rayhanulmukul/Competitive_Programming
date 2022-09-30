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
    int n, zero = 0, ans = 0;
    cin >> n;
    int arr[n];
    int arr1[n];
    vector <int> v;
    vector <int> v1;
    F0R(i, n){
        cin >> arr[i];
        if(arr[i] == 0){
            zero++;
        }
    }
    F0R(i, n){
        cin >> arr1[i];
        if(arr[i] == 0){
            v1.push_back(arr1[i]);
        }
        else v.push_back(arr1[i]);
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());

    int one = n - zero;
    //cout << one << " zero:" << zero << en;
    if(one == 0 || zero == 0){
        for(int i = 0; i < v.size(); i++){
            ans += v[i];
        }
        for(int i = 0; i < v1.size(); i++){
            ans += v1[i];
        }
        cout << ans << en;
    }
    else if(one > zero){
        ans += v[0];
        for(int i = v.size()-1; i >= v.size()-zero; i--){
            ans += (v[i]*2);
        }
        for(int i = v.size()-zero-1; i > 0; i--){
            ans += v[i];
        }
        for(int i = 0; i < v1.size(); i++){
            ans += (v1[i]*2);
        }
        cout << ans << en;
    }
    else if(zero > one){
        ans += v1[0];
        for(int i = v1.size()-1; i >= v1.size()-one; i--){
            ans += (v1[i]*2);
        }
        for(int i = v1.size()-one-1; i > 0; i--){
            ans += v1[i];
        }
        for(int i = 0; i < v.size(); i++){
            ans += (v[i]*2);
        }
        cout << ans << en;
    }
    else{
        if(v[0] >= v1[0]){
            ans += v1[0];
            for(int i = 1; i < v1.size(); i++){
                ans += (v1[i]*2);
            }
            for(int i = 0; i < v.size(); i++){
                ans += (v[i]*2);
            }
            cout << ans << en;
        }else{
            ans += v[0];
            for(int i = 1; i < v.size(); i++){
                ans += (v[i]*2);
            }
            for(int i = 0; i < v1.size(); i++){
                ans += (v1[i]*2);
            }
            cout << ans << en;
        }
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