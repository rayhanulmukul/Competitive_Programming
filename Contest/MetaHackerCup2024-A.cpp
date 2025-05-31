/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيمِ*/
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
#define pi 2 * acos(0.0)
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
#define rng(x, y) uniform_int_distribution<int>(x, y)(rng)
#define F0R(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a) F0R(i, 0, a)
const int MOD = 1e9 + 7; // 998244353;
const int MAX = 2e5 + 5;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

bool canDeliver(const vector<pair<int, int>> &windows, double speed)
{
    double currTime = 0.0;
    for (int i = 0; i < windows.size(); ++i)
    {
        int position = i + 1;
        currTime += (1.0 / speed);

        if (currTime < windows[i].first)
        {
            currTime = windows[i].first;
        }
        if (currTime > windows[i].second)
        {
            return false;
        }
    }
    return true;
}
double findMinimumSpeed(const vector<pair<int, int>> &windows)
{
    double low = 0.0;
    double high = 1e9;
    double result = -1;
    while (high - low > 1e-7)
    {
        double mid = (low + high) / 2.0;
        if (canDeliver(windows, mid))
        {
            result = mid;
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return result;
}
void solve(int tt)
{
    int N;
    cin >> N;
    vector<pair<int, int>> windows(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> windows[i].first >> windows[i].second;
    }
    double minSpeed = findMinimumSpeed(windows);
    if (minSpeed < 0)
    {
        cout << "Case #" << tt << ": -1" << endl;
    }
    else
    {
        cout << "Case #" << tt << ": " << fixed << setprecision(6) << minSpeed << endl;
    }
}
int32_t main()
{
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}