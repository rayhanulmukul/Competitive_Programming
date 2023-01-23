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
void bfs(int a, int b){
    map <int, int> m1;
    map <int, int> m2;
    queue <int> q1;
    vector <int> v1;

    q1.push(a);
    int flag = 0;
    while(!q1.empty()){
        int u, v, u1, v1;
        u = q1.front();
        q1.pop();

        m1[u] = 1;
        v = u*2;
        if(m1[v] == 0 && v <= b){
            q1.push(v);
            m1[v] = 1;
            m2[v] = u;
            if(v == b){
                flag = 1;
                break;
            }
        }
        v1 = u*10 + 1;
        if(m1[v1] == 0 && v1 <= b){
            q1.push(v1);
            m1[v1] = 1;
            m2[v1] = u;
            if(v1 == b){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        cout << "YES" << endl;
        int x = b;
        while(x != a){
            v1.pb(x);
            x = m2[x];
        }
        v1.pb(a);
        reverse(v1.begin(), v1.end());
        for(int i = 0; i < v1.size(); i++){
            cout << v1[i] << gap;
        }
        cout << endl;
    }
    else cout << "NO" << endl;
}
void solve(int tt){
    int a, b;
    cin >> a >> b;
    bfs(a, b);
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