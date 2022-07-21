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

int Binary_search(int arr[], int x, int low, int high){
    if(high >= low){
        int mid = low + (high - low)/2;
        if(arr[mid] == x) return mid;
        if(arr[mid] > x) return Binary_search(arr, x, low, mid - 1);    // Left Shift Working
        return Binary_search(arr, x, mid+1, high);  // Right Shift
    }
    return -1;
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
    while(t--){
        int n, x;
        cin >> n >> x;
        int arr[n];
        F0R(i, n) cin >> arr[i];
        int result = Binary_search(arr, x, 0, n-1);
        if(result == -1) cout << "Not Found" << en;
        else cout << "Elements found" << en;

    }
    return 0;
}