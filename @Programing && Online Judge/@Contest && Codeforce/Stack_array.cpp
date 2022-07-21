#include <bits/stdc++.h>
using namespace std;
int arr[100];
int len = 0;
void push(int a){
    arr[len] = a;
    len++;
}
void top(){
 for(int i = len-1; i >= 0; i--){
        cout << arr[i] << endl;
    }
}
int main(){
    string s = "8,7,5,+,-";
    s = s + ")";

    push(3);
    push(7);
    push(8);

    top();
}