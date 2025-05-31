#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *link;
};
Node *head = NULL;

void push(int a){
    Node * new_node = new Node;
    new_node -> data = a;
    new_node -> link = head;
    head = new_node;
}
void pop(){
    if(head == NULL){
        cout << "Stack Underflow" << endl;
    }
    else{
        Node *temp = head;
        head = head -> link;
        delete []temp;
    }
}
int top(){
    if(head == NULL){
        cout << "Stack is empty" << endl;
        return -1;
    }else{
        return head -> data;
    }
}

int main(){
    push(4);
    push(7);
    push(9);

    cout << "The top is " << top() << endl;
    pop();
    cout << "The top is " << top() << endl;
    pop();
    cout << "The top is " << top() << endl;
}