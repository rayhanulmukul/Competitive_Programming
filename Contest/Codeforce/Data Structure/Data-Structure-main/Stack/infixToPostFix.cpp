#include<bits/stdc++.h>
using namespace std;

int getPriority(char ch) {
    
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch == '.')) return 0;
    else return -1;

}

string infixToPostFix(string infix) {
    stack<char>stk;
    int i = 0;

    string postfix = "";
    for(i = 0; infix[i]; i++) {
        char ch = infix[i];
        if(ch == '(') stk.push(ch);
        else if(ch == ')') {
            while(!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                postfix += ',';
                stk.pop();
            }
            stk.pop();
        }

        else {
            int priority = getPriority(ch);
            if(priority == 0) {
                while(getPriority(infix[i]) == 0) {
                    postfix += infix[i];
                    i++;
                }
                i--;
                postfix += ',';
            }
            else {
                if(stk.empty()) stk.push(ch);
                else {
                while(!stk.empty() && stk.top() != '(' && (priority <= getPriority(stk.top()))) {
                    postfix += stk.top();
                    postfix += ',';
                    stk.pop();
                }
                stk.push(ch);
                }
            }
        }
    }
    while(!stk.empty()) {
        postfix += stk.top();
        postfix += ',';
        stk.pop();
    }
    postfix.erase(postfix.end()-1);  
    return postfix;
}

int main() {

    string infix = "A+(180.5*C-(D/E^F)*G)*2.0";
    string postfix = infixToPostFix(infix);

    cout << postfix << endl;
    return 0;
}
