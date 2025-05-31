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
        node *p = (node*)malloc(sizeof(node));
        p = head;
        while(p -> link != NULL){
            p = p -> link;
        }
        p -> link = tem;
    }
}
void deleteNode(int position){
    if(position == 1){
        node * tem;
        tem = head;
        head = head -> link;
        free(tem);
    }else{
        node *tem1 = (node *) malloc(sizeof(node));
        tem1 = head;
        for(int i = 1; i <= position - 2; i++){
            tem1 = tem1 -> link; 
        }
        node * tem2;
        tem2 = tem1 -> link;
        tem1 -> link = tem2 -> link;
        free(tem2);
    }
}
int main(){
    head = NULL;
    insert(6);
    insert(10);
    insert(15);
    deleteNode(1);
    print();
    deleteNode(3);
    print();

    return 0;
}