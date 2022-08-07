#include <bits/stdc++.h>
using namespace std;
typedef struct Node node;
struct Node{
    int value;
    node* next;
    
};
node* Head;
void store(int Data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> value = Data;
    new_node -> next = NULL;
    if(Head == NULL){
        Head = new_node;
    }else{
        node * tem = Head;
        while(tem -> next != NULL){
            tem = tem -> next;
        }
        tem -> next = new_node;
    }
}
void Display(){
    node* temp = (node*) malloc (sizeof(node));
    temp = Head;
    while(temp != NULL){
        cout << temp -> value << endl;
        temp = temp -> next;
    }
}
int main(){
    Head = NULL;
    store(5);
    store(3);    
    store(9);
    store(42);
    store(0);
    store(10);

    Display();
    return 0;
}    

