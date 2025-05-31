#include <bits/stdc++.h>
using namespace std;
int count = -1;
struct node{
    int data;
    struct node* next;
    struct node* prev;
} node_t;
node_t last;
void create(){
    last = (struct node*) malloc(sizeof(node_t));
    last = NULL;
    count = 0;
}
void push(int val){
    node_t* temp;
    temp = (struct node*) malloc(sizeof(temp));
    temp -> data = val;
    temp -> next = NULL;
    temp -> prev = last;
    if(last == NULL){
        last -> next = val;
        last = temp;
    }
    else last = temp;
    count++;
}
void display(){
    node_t* temp;
    while(!temp.empty()){
        
    }
}
int main(){
    create();
    push(2);
    push(4);
    push(3);
    display();
}