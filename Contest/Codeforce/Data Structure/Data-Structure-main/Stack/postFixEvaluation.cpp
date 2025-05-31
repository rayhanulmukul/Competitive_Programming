#include<bits/stdc++.h>
using namespace std;

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

    string p = "a,2,^";
    double x = postfixEvaluate(p);
    cout << x << endl;
    return 0;
}
