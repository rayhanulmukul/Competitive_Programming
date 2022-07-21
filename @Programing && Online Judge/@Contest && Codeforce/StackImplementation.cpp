#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *link;
};
Node *top = NULL;

void push(int value){
    Node *ptr = new (Node);
    ptr -> data = value;
    ptr -> link = top;
    top = ptr;
}
void pop(){
    if(top == NULL){
        cout << "Stack is UnderFlow." << endl;
    }else{
        Node *tem = top;
        top = top -> link;
        delete []tem;
    }
}
int topFunt(){
    if(top == NULL){
        cout << "Stack is empty." << endl;
        return 1;
    }else{
        return top -> data;
    }
}
int main(){
    push(5);
    push(8);
    push(12);
    push(7);
    cout << topFunt() << endl;
}