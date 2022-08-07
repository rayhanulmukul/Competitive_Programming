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

double calculate(double a, double b, char ch) {
    switch(ch) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return pow(a, b);
    }
}

double postfixEvaluate(string postfix) {
    stack<double>stk;

    int i;
    for(i = 0; i < postfix[i]; i++) {
        char ch = postfix[i];

        if(ch == ',' || ch == ' ') continue;
        else if(ch >= '0' && ch <= '9') {
            string str = "";
            while(postfix[i] != ',' && postfix[i]) {
                str += postfix[i];
                i++;
            }
            double num = stod(str);   
            stk.push(num); 
        }
        else if(ch >= 'a' && ch <= 'z'  || ch >= 'A' && ch < 'Z') {

            double value;
            cout << "Enter the value of " << ch << " : ";
            cin >> value;
            stk.push(value);
        }

        else {
            double b = stk.top();
            stk.pop();
            double a = stk.top();
            stk.pop();
            stk.push(calculate(a, b, ch));
        }
    }
    return stk.top();
}

int main() {

    string infix = "a+5.0*(2+3)-b";
    string postfix = infixToPostFix(infix);

    cout << "Infix : " << infix << endl;
    cout << "Postfix : " << postfix << endl;

    double ans = postfixEvaluate(postfix);

    cout << "Answer : " << ans << endl;

    return 0;
}
