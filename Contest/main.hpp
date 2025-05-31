vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "[Line_" << LINE_NUM << "]=> ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef TESLA
#define dbg(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define dbg(...)
#endif

#ifndef ONLINE_JUDGE
//#define cerr cout
#include "ram.hpp"
#else
#define dbug(...)
#endif
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl

const auto start_time = chrono::high_resolution_clock::now();
void run_time() {
    // will work for ac,cc&&cf.
#ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end_time - start_time;
    cout << "\n\n\nTime Taken : " << diff.count();
#endif
}
// output_run_time();