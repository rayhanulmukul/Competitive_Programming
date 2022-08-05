#include<bits/stdc++.h>
using namespace std;
#define int long long

int fib(int a){
    if(a == 1) return 0;
    if(a == 2) return 1;
    return fib(a-1)+fib(a-2);
}

int32_t main(){
    int a; cin >> a;
    cout << fib(a) << endl;
}