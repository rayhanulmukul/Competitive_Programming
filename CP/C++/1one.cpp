#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0), cin.tie(0)
#define f0(i,n)  for(int i = 0; i<n; i++)
#define f1(i,n)  for(int i = 1; i<=n; i++)
#define f2(i,n)  for(int i = 1; i<n; i++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define int long long
#define INF 1000000000
#define mod 1000000007
int Ceil(int a, int b) { return a/b+(a%b != 0); }
int zero = 0;
void sol()
{
    int n;cin>>n;
    vi v(n);
    f0(i,n)cin>>v[i];
    int ans = 0;
    if(n & 1){
        for(int i = 1; i<n; i+=2){
            if(v[i]<(v[i-1]+v[i+1])){
                ans += max(v[i-1],v[i+1]) - v[i]+1;
            }
        }
        cout << ans << endl;
        return;
    }
    vi pre(n+1, 0),suf(n+1, 0);

    for(int i=1 ; i+1<n ; i+=2){
        pre[i+1] = pre[i-1] + max(zero,max(v[i+1],v[i-1])-v[i]+1);
    }
    for(int it= 0; it<n; it++)cout<<pre[it]<<" ";cout<<endl;
    for(int i=n-2 ; i>=2; i-=2){
        suf[i-1] = suf[i+1] + max(zero,max(v[i+1],v[i-1])-v[i]+1);
    }
    for(int it = 0; it<n; it++)cout<<suf[it]<<" ";cout<<endl;

    int res = LLONG_MAX;
    int temp;
    for(int i = 0; i<n-1; i+=2){
        temp = pre[i]+suf[i+1];
        cout << temp<< " "<<i<<" "<<i+1<<endl;
        res = min(res, temp);
    }
    cout << res << endl;

}

int32_t main(){
    FastIO;
    int tt;
    tt = 1;
    cin>>tt;
    while(tt--){
        sol();
    }
}
// 0 0 1000000000 0 1000000000 0 1999800700 0 1999800700 0 2500501600 0 
// 0 2198196903 0 1198196903 0 1197997603 0 898698402 0 499299101 0 0
// 2197997603
