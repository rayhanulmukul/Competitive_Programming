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

void solve(int tt){
    int a, b, k = 0;
    cin >> a >> b;
    char arr[a][b];
    F0R(i, a){
        F0R(j, b){
            cin >> arr[i][j];
            if(arr[i][j] == '^'){
                k = 1;
            }
        }
    }
    if(k == 0){
        cout << "Case #" << tt << ": " << "Possible" << en;
        F0R(i, a){
            F0R(j, b){
                cout << arr[i][j];
            }
            cout << en;
        }
        return;
    }
    if(k == 1){
        F0R(i, a){
            F0R(j, b){
                if(arr[i][j] != '#' && arr[i][j] == '^'){
                    if(j+1 < b && arr[i][j+1] != '#'){
                        arr[i][j+1] = '^';
                    }if(i+1 < a && arr[i+1][j] != '#'){
                        arr[i+1][j] = '^';
                    }if(j-1 >= 0 && arr[i][j-1] != '#'){
                        arr[i][j-1] = '^';
                    }if(i-1 >= 0 && arr[i-1][j] != '#'){
                        arr[i-1][j] = '^';
                    }
                }
            }
        }
    }
    for(int i = 0; i < a; i++){
        int c = 0;
        for(int j = 0; j < b; j++){
            c = 0;
            if(arr[i][j] == '^'){
                c++;
                if(j+1 < b && arr[i][j+1] == '^'){
                    c++;
                }if(i+1 < a && arr[i+1][j] == '^'){
                    c++;
                }if(j-1 >= 0 && arr[i][j-1] == '^'){
                    c++;
                }if(i-1 >= 0 && arr[i-1][j] == '^'){
                    c++;
                }
                if(c < 2){
                    cout << "Case #" << tt << ": " << "Impossible" << en;
                    return;
                }
            }
        }
        cout << c << en;
    }
    cout << "Case #" << tt << ": " << "Possible" << en;
    F0R(i, a){
        F0R(j, b){
            cout << arr[i][j];
        }
        cout << en;
    }

}
int32_t main(){
    #ifndef DEBUG
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}