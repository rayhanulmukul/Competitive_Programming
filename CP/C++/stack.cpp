#include<bits/stdc++.h>
using namespace std;

struct mystack
{
    static const int N = 500;
    int arr[N];
    int len = 0;
    void push(int ele){
        if(len == N){
            cout << "Stack overflow" << endl;
            return;
        }else{
            arr[len] = ele;
            len++;
        }
    }
    int pop(){
        if(len == 0){
            cout << "Error: Stack is empty!!" << endl;
        }else{
            len--;
            return arr[len];
        }
    }

};
int eval(int a, int b, char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
}

int main(){
    mystack ami;
    ami.push(5);
    ami.push(60);
    cout << ami.pop() << endl;
    cout << ami.pop() << endl;
    //postfix evaluation
    string equ = "55 60 7 + -";
    mystack cal;
    int num = 0;
    for(auto a: equ){
        if(a == ' '){
            if(num != 0) cal.push(num);
            num = 0;
            continue;
        }
        if(isdigit(a)){
            num *= 10;
            num += a-'0';
        }else{
            //now do the operation
            if(cal.len < 2){
                cout << "Invalid Equation" << endl;
                return 0;;
            }
            int last = cal.pop();
            int prvLast = cal.pop();
            cal.push(eval(prvLast, last, a));
        }
    }
    cout << cal.pop() << endl;
}