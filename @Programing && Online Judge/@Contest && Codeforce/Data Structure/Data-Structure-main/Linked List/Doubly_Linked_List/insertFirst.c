#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} *head, *tail;

typedef struct Node node;

void insertFirst(int data) {
    node *newNode = (node*) (malloc(sizeof(node)));

    newNode -> data = data;
    newNode -> prev = NULL;

    if(head == NULL) {
        head = tail = newNode;
        tail->next = NULL;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
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


    for(int i = 1; i <= 10; i++) insertFirst(i);

    display();

    return 0;
}
