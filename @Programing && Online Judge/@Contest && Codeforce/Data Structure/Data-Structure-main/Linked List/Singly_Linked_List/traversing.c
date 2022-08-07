#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
}*head;
typedef struct Node node;


node* getNode(int data){
    node* temp;
    temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void addEnd(int data) {
    node * temp = getNode(data);
    if(head == NULL) {
        head = temp;
    }
    else {
        node * temp1;
        temp1 = head;
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void traversal() {
    node * temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() 
{

    for(int i = 0; i < 10; i++) {
        addEnd(i+1);
    }

    traversal();

    return 0;
}
