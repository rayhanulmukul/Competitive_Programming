#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define ft front()
#define bk back()
#define pi 2*acos(0.0)
#define gap ' '
#define en '\n'
#define endl en
#define mem(a, b) memset(a, b, sizeof(a))
#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

int t;
void solve(int tt){
    string s;
    getline(cin, s);
    int n = s.size();
    if(n == 0){
        return;
    }
    //dbg(s);
    string day = s.substr(0, 2);
    string month = s.substr(3, 2);
    string year = s.substr(6, 4);
    string weekDay = s.substr(11, 3);
    //dbg(day, month, year, weekDay);
    int d = stoi(day);
    cout << "|---------------------------|" << endl;
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << endl;
    cout << "|---------------------------|" << endl;
    cout << "|";
    int cnt = 0;
    string givenDay[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    if(weekDay == "Sun"){
        cnt = 0;
    }else if(weekDay == "Mon"){
        cnt = 1;
    }else if(weekDay == "Tue"){
        cnt = 2;
    }
    else if(weekDay == "Wed"){
        cnt = 3;
    }
    else if(weekDay == "Thu"){
        cnt = 4;
    }
    else if(weekDay == "Fri"){
        cnt = 5;
    }
    else if(weekDay == "Sat"){
        cnt = 6;
    }
    int mon1 = 31, mon2 = 28, mon3 = 31, mon4 = 30, mon5 = 31, mon6 = 30, mon7 = 31, mon8 = 31, mon9 = 30, mon10 = 31, mon11 = 30, mon12 = 31;
    if(month == "02"){
        if(((stoi(year) % 4 == 0 && stoi(year) % 100 != 0)) || (stoi(year) % 400 == 0)){
            mon2 = 29;
        }
    }
    int mon = stoi(month);
    int year1 = stoi(year);
    int arr[12] = {mon1, mon2, mon3, mon4, mon5, mon6, mon7, mon8, mon9, mon10, mon11, mon12};
    for(int k = 1; k <= 12; k++){
        if(k == mon){
            d %= 7;
            for(int i = 0; i < 7; i++){
                if(givenDay[i] == weekDay){
                    cnt = i;
                    break;
                }
            }
            for(int i = 0; i < d; i++){
                cnt--;
                if(cnt < 0){
                    cnt = 6;
                }
            }
            cnt++;
            cnt %= 7;
            //dbg(x, cnt);
            int nextDay = (6 - cnt + 1) + 4 * 7;
            //dbg(nextDay, cnt);
            int cnt1 = 0;
            for(int i = 1; i <= cnt; i++){
                if(nextDay < arr[k - 1]){
                    cout << " " << nextDay + 1 << "|";
                    nextDay++;
                }
                else cout << " - |";
                cnt1++;
            }
            int i;
            int week = 1;
            for(i = 1; i <= arr[k - 1]; i++){
                if(cnt1 == 7){
                    week++;
                    if(week == 6) break;
                    cout << endl;
                    cout << "|---------------------------|" << endl;
                    cout << "|";
                    cnt1 = 0;
                }
                if(i < 10){
                    cout << "  " << i << "|";
                }else{
                    cout << " " << i << "|";
                }
                cnt1++;
            }
            //dbg(mon1, week);
            for(int j = arr[k - 1] + 1; j <= 35; j++){
                if(week == 6) break;
                else if(cnt1 == 7){
                    week++;
                    if(week == 6) break;
                    cout << endl;
                    cout << "|---------------------------|" << endl;
                    cout << "|";
                    cnt1 = 0; 
                }
                cout << " - |";
                cnt1++;
            }
            cout << en;
            //dbg(t, tt);
            if(tt == t + 1) cout << "|---------------------------|" << endl;
            else{
                cout << "|---------------------------|" << endl << endl;
            }
        }
    }
}
int32_t main(){
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    cin >> t;
    for(int i = 1; i <= t  + 1; i++){
        solve(i);
    }
    return 0;
}