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
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int(x.size()))
#define sor(x)  sort(x.begin(), x.end())

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)


const int N = 100000000;
vector <int> low(N+1), pm;
void sieve(){
    for(int i = 2; i <= N; i++)
        low[i] = i;
    for(int i = 2; i * i <= N; i++){
        if(low[i] == i)
            for(int j = 2 * i; j <= N; j += i)
                if(low[j] == j)
                    low[j] = i;
    }
}
vector <int> prime_fact(int x){
        vector <int> res;
        while(x > 1){
            res.push_back(low[x]);
            x /= low[x];
        }
        return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    sieve();
    int t = 1;
    //cin >> t;
    while(1){
        int x;
        cin >> x;
        if(x == 0) break;
        else {
            vector <int> pf = prime_fact(x);
		    for(auto it : pf){
			cout << it << " ";
            }
		}
    }
    return 0;
}