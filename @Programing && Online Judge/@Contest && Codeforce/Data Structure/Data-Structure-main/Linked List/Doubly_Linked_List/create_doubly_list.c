#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} *head, *tail;

typedef struct Node node;

void display() {
    node * temp;

    temp = head;

    printf("Printing forward...\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        tail = temp;
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

    node *node2, *node3, *node4;

    head = (node*) malloc(sizeof(node));
    node2 = (node*) malloc(sizeof(node));
    node3 = (node*) malloc(sizeof(node));
    node4 = (node*) malloc(sizeof(node));

    head -> data = 10;
    head ->prev = NULL;
    head -> next = node2;

    node2 -> data = 100;
    node2 -> prev = head;
    node2 -> next = node3;

    node3 -> data = 1000;
    node3 -> prev = node2;
    node3 -> next = node4;

    node4 -> data = 10000;
    node4 -> prev = node3;
    node4 -> next = NULL;

    display();
}
