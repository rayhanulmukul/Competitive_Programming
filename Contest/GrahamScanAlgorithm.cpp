#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
#include<vector>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int)(x.size())
#define mem(a, b) memset(a, b, sizeof(a))
#define sor(x)  sort(x.begin(), x.end())

#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
//dbug(), watch(), output_run_time()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
#define R0F(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) R0F(i,0,a)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;
    
struct Point { int x, y; };

int orientation(Point p, Point q, Point r) {
    //cout << "Orientation : " << (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y) << endl;
    //dbg(p.x, p.y, q.x, q.y, r.x, r.y);
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);  // 0, 1, 2 = colinear, clockwise, counterclockwise
}
vector<Point> convexHull(vector<Point> points) {
    int n = points.size();       
    sort(points.begin(), points.end(), [](Point a, Point b) {
        return (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });
    
    vector<Point> hull;
    for (int i = 0; i < 2*n; i++) {
        int j = (i < n) ? i : 2*n - 1 - i;
        while (hull.size() >= 2 && orientation(hull[hull.size()-2], hull.back(), points[j]) <= 0)
            hull.pop_back();
        hull.push_back(points[j]);
    }
    hull.pop_back();
    return hull;
}
void solve(int tt){
    vector<Point> points;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.pb({x, y});
    }
    vector<Point> hull = convexHull(points);
    for (Point p : hull) cout << "(" << p.x << ", " << p.y << ")" << endl;
}
int32_t main(){
    #ifndef DEBUG
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    #endif
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}