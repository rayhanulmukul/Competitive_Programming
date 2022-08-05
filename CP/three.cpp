//Date: 2021-08-18 12:25:33
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(ll i=a;i<(ll)b;i++)
#define FORr(i,a,b) for(ll i =a;i>=(ll)b;i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define print(arr)  for(auto a: arr) cout << a<< " "; cout << endl;
#define in(a) ll a; cin >> a;
#define inp(arr,n) vector<ll>arr(n); for(auto &a: arr) cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vi vector<ll>
#define s second
ll mod = 1e9 + 7;
#define case cout << "Case "<< tt << ": ";
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
#define pll pair<ll, ll>
#define set_bit(x, idx) x = x|(1LL<<idx)
ll dx[8] = {0,1,0,-1,1,-1,1,-1};
ll dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define endl "\n"
#define yes cout << "Yes\n";
#define no cout << "No\n";

#ifdef DEBUG
#define pause(x) thamm
#define ios
#define dbg(...) cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#define ok tikkk
#else
#define pause(x) 
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(...) 
#define ok
#endif
#define db double
vector<pll>arr;
#define lll __int128_t
int n;
lll howmany(string now){ //numbers of 1stbee less than of equal to this
    if(now == "0") return 0;
    reverse(all(now));
    lll ans = 0;
    for(int i = 0; i < now.size()-1; i++){
        ans += pow(10,i);
    }
    if(now.back() == '1'){
        now.pop_back();
        reverse(all(now));
        if(!now.empty()) ans += stoll(now);
        ans ++;
    }else{
        ans += pow(10, now.size()-1);
    }
    return ans;
}
db dp[1005][1005];
db solve(int idx, int nums){
    if(dp[idx][nums] != -1) return dp[idx][nums];
    if(idx == arr.size()) return dp[idx][nums] = nums == 0;
    db anp = howmany(to_string(arr[idx].s)) - howmany(to_string(arr[idx].f-1));
    db ans = anp*solve(idx+1, nums-1);
    anp = (arr[idx].s - arr[idx].f + 1)-anp;
    ans += anp*solve(idx+1, nums);
    double ase = (arr[idx].s-arr[idx].f+1);
    ans /= ase;
    dbg(idx, nums, ans);
    return dp[idx][nums] = ans;
}

void solvetc(ll tt){
    cin >> n;
    arr.resize(n);
    for(auto &a: arr) cin >> a.f >> a.s;
    db ans = 0;
    rep(i,1005) rep(j, 1005) dp[i][j] = -1;
    in(k); 
    int count = k*n; count = (count+100-1)/100;
    for(int i = count; i <= n; i++){
        ans += solve(0, i);
    }
    cout << setprecision(10) << fixed <<ans << endl;
}

int32_t main()
{
    ios ;
    #ifdef DEBUG
    //freopen("in", "r", stdin);
    #endif
    ll nn = 1;
    //cin >> nn;
    rep(i, nn) solvetc(i+1);
}