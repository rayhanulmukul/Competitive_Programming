#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} *head, *tail;

typedef struct Node node;

void insertLast(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));

    newNode -> data = item;
    newNode -> next = NULL;

    if(head == NULL) {
        head = tail = newNode;
        head -> prev = NULL;
    }
    else {

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

    }
}

void display() {
    
    node * temp;

    temp = head;
    printf("Printing forward...\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Printing backward...\n");
    temp = tail;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {

    for(int i = 1; i <= 10; i++) insertLast(i);

    display();

    return 0;
}
