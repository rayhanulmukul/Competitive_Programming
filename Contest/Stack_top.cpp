#include<bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

void call (stack <int> &s){
    cout << s.size() << "elements on stack" << endl;
}
void callTop (stack <int> &s){
    cout << s.top() << "Top elements" << endl;
}
int main(){
    stack <int> s;
    s.push(3);
    s.push(6);
    s.push(51);

    call(s);
    callTop(s);
    call(s);
    s.pop();

    call(s);
    callTop(s);
}