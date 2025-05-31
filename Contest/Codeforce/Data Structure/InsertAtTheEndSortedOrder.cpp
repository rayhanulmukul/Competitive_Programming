#include <bits/stdc++.h>
using namespace std;
typedef struct Node node;
struct Node{
    int data;
    node *link;
};
node* head;
void print(){
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> link;
    }
    cout << endl;
}
void insert(int value){
    node * tem = (node *) malloc(sizeof(node));
    tem -> data = value;
    tem -> link = NULL;
    if(head == NULL){
        head = tem;
    }else{
        node *p = (node*)malloc(sizeof(node));
        p = head;
        while(p -> link != NULL){
            p = p -> link;
        }
        p -> link = tem;
    }
}
void insert_Order( int value){
    node * tem1 = (node*)malloc(sizeof(node));
    tem1 -> data = value;
    if(head == NULL || tem1 -> data < head -> data){
        tem1 -> link = head;
        head = tem1;
    }
    else{
        node* pred = head;
        node* p = pred -> link;
        while(p != NULL && p -> data < tem1 -> data){
            pred = p;
            p = p -> link;
        }
        pred -> link = tem1;
        tem1 -> link = p;
    }
}
int main(){
    head = NULL;
    insert(6);
    insert(10);
    insert(15);
    print();
    insert_Order(20);
    print();

    return 0;
}