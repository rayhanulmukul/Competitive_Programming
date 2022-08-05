#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<(int)b;i++)
#define FORr(i,a,b) for(int i =a;i>=(int)b;i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define print(arr)  for(auto a: arr) cout << a<< " "; cout << endl;
#define in(a) int a; cin >> a;
#define inp(arr,n) vector<int>arr(n); for(auto &a: arr) cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vi vector<int>
#define s second
#define mxheap priority_queue<int>
#define mnheap priority_queue<int, vector<int>, greater<int>>
#define mxheap2 priority_queue<pair<int,int>>
#define mnheap2 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
#define case cout << "Case "<< tt << ": ";
inline int uceil(int a,int b) {return (a % b ? a / b + 1 : a / b);}
#define pll pair<int, int>
#define set_bit(x, idx) x = x|(1LL<<idx)
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define endl "\n"
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define db long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)



void solvetc(int tt){
    in(n) 
    deque<int>ap(n);
    for(auto &a: ap) cin >> a;
    vector<int>ans = {0};
    while(!ap.empty()){
        if(ap.front() <= ap.back()){
            if(ans.back() > ap.front()) {
                if(ans.back() > ap.back()) break; 
                ans.pb(ap.back());
                ap.pop_back();
                continue;
            }
            ans.pb(ap.front());
            ap.pop_front();
        }else{
            if(ans.back() > ap.back()){
                if(ans.back() > ap.front()) break;
                ans.pb(ap.front());
                ap.pop_front();
                continue;
            } 
            ans.pb(ap.back());
            ap.pop_back();
        }
        //dbg(ap, ans);
    }
    cout << "Case #"<< tt <<": ";
    cout << ans.size()-1 << endl;
}

int32_t main()
{
    int nn = 1;
    cin >> nn;
    rep(i, nn) solvetc(i+1);
}