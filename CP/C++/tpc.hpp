
void dbg2(int* arr, int low, int hi){
    for(int i = low; i <= hi; i++) cout << arr[i] << " ";
    cout << endl;
}
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T, typename T2> ostream& operator<<(ostream &os, const unordered_map<T,T2> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, typename T2> ostream& operator<<(ostream &os, const map<T,T2> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const priority_queue<T> &v) { os << '{'; string sep; priority_queue<T>vv = v; while(!vv.empty()) {os << sep << vv.top(), sep = ", "; vv.pop();} return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const queue<T> &v) { os << '{'; string sep; queue<T>vv = v; while(!vv.empty()) {os << sep << vv.front(), sep = ", "; vv.pop();} return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const deque<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const multiset<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define tikkk cerr << __LINE__ << " is done " << endl;
#define thamm(x) this_thread::sleep_for(chrono::milliseconds(x));
/*
#define lll __int128_t
ll hash58 = 288230376151711717;
ll hash32 = 1610612741;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
*/
