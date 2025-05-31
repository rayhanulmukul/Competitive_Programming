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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int *arr[5], num[5];
    int i, j, n;
    for(i = 0; i < 5; i++){
        cout << "Enter ther number of students for class %d : << i + 1 << en;
        cin >> n;
        num[i] = n;
        arr[i] = (int *)malloc(sizeof(int)*n);
        if(arr[i] == NULL){
            cout << "Memory Allocation Failed" << en;
            return 1;
        }
        for(j = 0; j < n; j++){
            cout << "Enter marks for student : " << j + 1 << en;
            cin >> arr[i][j];
        }
        cout << "Output" << en;
        for(i = 0; i < 5; i++){
            cout << "Class : " << i+1 << en;
            for(j = 0; j < num[i]; j++){
                cout << 
            }
        }

    }
    return 0;
}