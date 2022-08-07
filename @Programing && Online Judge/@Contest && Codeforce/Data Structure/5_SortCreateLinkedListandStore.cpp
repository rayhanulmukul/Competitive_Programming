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
    if(Head == NULL){
        Head = new_node;
        Head -> next = Head;
        return;
    }else{
        node * tem = Head;
        while(tem -> next != Head){
            tem = tem -> next;
        }
        tem -> next = new_node;
        new_node -> next = Head;
    }
    Head = new_node;
}
void Display(){
    node* temp;
    temp = Head;
    do{
        cout << temp -> value << endl;
        temp = temp -> next;
    }while(temp != Head);
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





