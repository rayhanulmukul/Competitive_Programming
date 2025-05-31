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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

int arr[1000];
void insert(int root, int ele){
    if(arr[root] == 0){
        arr[root] = ele;
    }else if(arr[root] < ele){
        insert(root*2 + 1, ele);
    }else{
        insert(root*2, ele);
    }
    cout << "ROOT" << root << " ";
}
void print(){
    for(int i = 0; i < 50; i++){
        if(arr[i] == 0) cout << " ";
        else cout << arr[i] << en;
    }
    cout << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, root = 1;
        cin >> n;
        insert(root, n);
        cout << en;
       //print();
    }
    
    return 0;
}