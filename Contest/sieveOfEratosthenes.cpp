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
const int PRIME = 1000000;
#define gap ' '
#define en '\n'
#define sz(x) (int(x.size()))
#define sor(x)  sort(x.begin(), x.end())

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
bool marked[10000000];
vector <int> v;
void sieve(int n){
	for(ll i = 3; i*i <= n; i+=2){
		if(marked[i] == false){
			for(ll j = i*i; j <= n; j += i){
                marked[j] = true;
            }
		}
	}
    v.push_back(2);
    for(int i = 3; i <= n; i+=2){
        if(marked[i] == false) v.push_back(i);
    }
}
void solve(){
    int n, c = 0;
    cin >> n;
    auto it = lower_bound(v.begin(), v.end(), n);
    if(*it == n) cout << it - v.begin() + 1 << en;
    else cout << it - v.begin() << en;
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
    sieve(PRIME);
	while(t--){
        solve();}
	return 0;
}