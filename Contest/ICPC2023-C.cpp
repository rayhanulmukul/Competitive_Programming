#include <bits/stdc++.h>
using namespace std;


#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
void solve(int tt) {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int ans = 0;
    dbg(v);
    for (int i = 0; i < n-1; i++) {
        int low = lower_bound(v.begin(), v.end(), a - v[i]) - v.begin();
        int high = upper_bound(v.begin(), v.end(), b - v[i]) - v.begin();

        dbg(a - v[i], low, b - v[i], high);
        low = max(low, i + 1);
        high = max(high, i + 1);
        dbg(low, high);
        int count = high - low;
        ans += count;
        cout << endl;
    }
    //ans /= 2;
    cout << "Case " << tt << ": " << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    return 0;
}
