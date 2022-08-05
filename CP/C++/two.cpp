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
#define mxheap priority_queue<ll>
#define mnheap priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2 priority_queue<pair<ll,ll>>
#define mnheap2 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
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
#define db long double



#ifdef DEBUG
#include "tpc.hpp"
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)


void solvetc(ll tt){
	int x = rng(1,10);
	vector<int>pm;
	for(int i = x; i <= 50; i++){
		int la = i/x;
		la = i/la;
		pm.pb(la);
		dbg(i%x, la, x, i/x);
	}
	if(is_sorted(all(pm))){
		cout<< tt << endl;
	}else{
		exit(0);
	}
}

int32_t main()
{
	ios ;
	#ifdef DEBUG
	//freopen("in", "r", stdin);
	#endif
	ll nn = 100;
	rep(i, nn) solvetc(i+1);
}

