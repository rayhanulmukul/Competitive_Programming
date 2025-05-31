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
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

void solve(int tt)
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    unordered_map<int, vector<int>> indicesMap;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        indicesMap[numbers[i]].push_back(i);
    }

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] < 0)
        {
            int positiveValue = abs(numbers[i]);
            if (indicesMap[positiveValue].empty())
                continue;
            auto iter = lower_bound(indicesMap[positiveValue].begin(), indicesMap[positiveValue].end(), i);
            if (iter == indicesMap[positiveValue].begin())
                continue;
            iter--;
            int lowerCount = iter - indicesMap[positiveValue].begin() + 1;
            int upperCount = indicesMap[numbers[i]].size() - (lower_bound(indicesMap[numbers[i]].begin(), indicesMap[numbers[i]].end(), i) - indicesMap[numbers[i]].begin()) - 1;
            upperCount += indicesMap[positiveValue].size() - (upper_bound(indicesMap[positiveValue].begin(), indicesMap[positiveValue].end(), i) - indicesMap[positiveValue].begin());
            upperCount = n - (i + 1) - upperCount;
            result += (lowerCount * upperCount);
        }
        else if (numbers[i] > 0)
        {
            int negativeValue = numbers[i] * -1;
            if (indicesMap[negativeValue].empty())
                continue;
            auto iter = lower_bound(indicesMap[negativeValue].begin(), indicesMap[negativeValue].end(), i);
            if (iter == indicesMap[negativeValue].begin())
                continue;
            iter--;
            int lowerCount = iter - indicesMap[negativeValue].begin() + 1;
            int upperCount = indicesMap[numbers[i]].size() - (lower_bound(indicesMap[numbers[i]].begin(), indicesMap[numbers[i]].end(), i) - indicesMap[numbers[i]].begin()) - 1;
            upperCount += indicesMap[negativeValue].size() - (upper_bound(indicesMap[negativeValue].begin(), indicesMap[negativeValue].end(), i) - indicesMap[negativeValue].begin());
            upperCount = n - (i + 1) - upperCount;
            result += (lowerCount * upperCount);
        }
        else
        {
            if (i == *indicesMap[numbers[i]].begin())
                continue;
            int idx = lower_bound(indicesMap[numbers[i]].begin(), indicesMap[numbers[i]].end(), i) - indicesMap[numbers[i]].begin();
            int lowerCount = idx;
            int upperCount = indicesMap[numbers[i]].size() - lowerCount - 1;
            upperCount = n - (i + 1) - upperCount;
            result += (lowerCount * upperCount);
        }
    }

    cout << result << '\n';
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

/*2
7
1 -1 3 1 -1 0 -3
10
-1 -1 -2 2 0 1 0 3 1 0
*/