//Date: 2021-08-12 10:08:54
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

/*
-this is 1 based segtree
-have a global vector named arr
*/
struct jinis
{
    //Use required attributes
    int mn;

    //Default Values
    jinis() : mn(0) {};
};

struct SegTree
{
    int N;
    vector<jinis> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        fill(all(st), jinis{});
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
        build(1,1,n);
    }

    //Write reqd merge functions
    void merge(jinis &cur, jinis &l, jinis &r) 
    {
        cur.mn = __gcd(l.mn, r.mn);
    }
  
    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R)
    {
        if(L != R)
        {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] = lazy[node];
            lazy[node*2 + 1] = lazy[node]; 
        }
        st[node].mn = lazy[node];
        cLazy[node] = 0;
    }

    void build(int node, int L, int R)
    {
        if(L==R)
        {
            st[node].mn = arr[L];
            return;
        }
        int M=(L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    jinis Query(int node, int L, int R, int i, int j)
    {
        if(cLazy[node])
        propagate(node, L, R);
        if(j<L || i>R)
            return jinis();
        if(i<=L && R<=j)
            return st[node];
        int M = (L + R)/2;
        jinis left=Query(node*2, L, M, i, j);
        jinis right=Query(node*2 + 1, M + 1, R, i, j);
        jinis cur;
        merge(cur, left, right);
        return cur;
    }

    jinis pQuery(int node, int L, int R, int pos)
    {
        if(cLazy[node])
        propagate(node, L, R);
        if(L == R)
            return st[node];
        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }  

    void Update(int node, int L, int R, int i, int j, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if(cLazy[node])
        propagate(node, L, R);
        if(L == R)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    jinis query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }

    jinis query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }
};

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


void solvetc(ll tt){
}

int32_t main()
{
    ios ;
    //freopen("in", "r", stdin);
    ll nn = 1;
    cin >> nn;
    rep(i, nn) solvetc(i+1);
}