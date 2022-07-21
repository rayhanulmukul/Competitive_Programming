#include <bits/stdc++.h>
using namespace std;
int pre(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}
void calculate_postfix(string result){
    stack <float> stack;
    int len = result.length();

    for(int i = 0; i < len; i++){
        if(result[i] <= 'z' && result[i] >= 'A'){
            int a = rand()%10;
            cout << "Random Number Input Character " << result[i] << " : " << a << endl;  
            result[i] = a+'0';
        }
        if(result[i] >= '0' && result[i] <= '9'){
            stack.push(result[i] - '0');
        }
        else{
            float a = stack.top();
            stack.pop();
            float b = stack.top();
            stack.pop();
            switch(result[i]){
                case '+':
                        stack.push(b + a);
                        break;
                case '-':
                        stack.push(b - a);
                        break;
                case '*':
                        stack.push(b * a);
                        break;
                case '/':
                        stack.push(float(b / a));
                        break;
                case '^':
                        stack.push(pow(b,a));
                        break;
            }
        }
    }
    cout << "\nPostfix Notation Calculation : ";
    cout << stack.top() << endl;
    //return stack.top();
}
void infixToPostfix(string s){
    string result;
    stack <char> st;
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }
        else if(c == '('){
            st.push('(');
        }
        else if(c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && pre(s[i]) <= pre(st.top())){
                if(c == '^' && st.top() == '^'){
                    break;
                }
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << "Infix To Postfix Notation : ";
    cout << result << endl;
   // cout << "\nPostfix Notation Calculation : ";
    calculate_postfix(result);
    //cout << endl;
}
int main(){
    srand(clock());
    string exp = "A+2*1+(2-D)";  //(A+(B*C-(D/E*F)*G)*H)
    infixToPostfix(exp);
    return 0;
}