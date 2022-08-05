#include<bits/stdc++.h>
using namespace std;
#define    int   long long 

 
void solve(){ 
    int n;
    cin >> n;
    int a[4];
    a[0]=0;
    a[1] = 2;
    a[2]=1;
    a[3]=1;
    cout << min((n/2)+a[n%2],(n/3) + a[n%3]) << endl;
    
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // #endif
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}