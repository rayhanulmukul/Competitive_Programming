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
#define gap ' '
#define en '\n'
#define sz(x) (int(x.size()))
#define sor(x)  sort(x.begin(), x.end())

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

void solve(){
    /* int n, ok = 0, ind;
    cin >> n;
    string s;
    cin >> s;
    vector <pair <int, int> > v;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && ok == 0){
            ok = 1;
            ind = i;
        }
        if(ok == 1 && s[i] == '0' && s[i+1] != 0 && i+1 < n){
            v.push_back(make_pair(ind+1, i-ind));
            ok = 0;
            ind = i;
        }
        else if(ok == 1 && s[i] == '0' && i == n-1){
            v.push_back(make_pair(ind+1, i-ind));
            ok = 0;
            ind = i;
        }
    }
    cout << v.size() << en;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << en;
    } */
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<vector<int>>res;

    for(int i = n-1;i>=0;i--){
      if(str[i]=='0'){
        int x = i+1;
        for(int j = 0;j<=i;j++) {
          if(str[j]=='1') str[j]='0';
          else str[j] = '1';
        }
        res.push_back({1ll,x});
      }
    }
    int siz = res.size();
    cout<<siz<<endl;
    for(auto x:res) cout<<x[0]<<" "<<x[1]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);n
    #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();}
    return 0;
}