#include <bits/stdc++.h>
using namespace std;
typedef struct Node node;
struct Node{
    int data;
    node *link;
};
node *head;
void print(){
    node *temp = (node *)malloc(sizeof(node));
    temp -> link = head;
    while(temp != NULL){
        cout << temp -> data << endl;
        temp = temp -> link;
    }
}
void insert(int value){
    node * tem = (node *) malloc(sizeof(node));
    tem -> data = value;
    tem -> link = NULL;
    if(head == NULL){
        head = tem;
    }else{
        node * t = head;
        while(t -> link != NULL){
            t = t -> link;
        }
        t = tem;
    }
}
int main(){
    head = NULL;
    insert(6);
    insert(10);
    insert(15);

    print();

    return 0;
}