#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data; 
   struct Node * next;
} *head;

typedef struct Node node;

void display() {
    node * temp = head;
    if(head == NULL) {
        printf("Nothing to print\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertFirst(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void insertLast(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode-> data = item;
    newNode->next = NULL;

    if(head == NULL) head = newNode;
    else {
        node * temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

}

void deleteLast() {
    node * temp, *temp1;
    temp = head;
    if(head == NULL) {
        printf("List underflow!\n");
        return;
    }
    if(head->next == NULL) {
        head = NULL;
        return;
    }
    while(temp->next != NULL) {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
}

int main()
{
    insertLast(565);
    insertLast(566);
    // insertLast(567);
    // insertFirst(564);
    // insertFirst(563);
    display();
    deleteLast();
    display();
    deleteLast();
    display();
    deleteLast();
   
    return 0;
}
