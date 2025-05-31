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

void insert_at_position(int data, int pos) {

    int i = 1;
    node *temp = head;
    while(i < pos-1 && temp != tail) {
        temp = temp->next;
        i++;
    }

    if(pos == 1) {
        insertFirst(data);
    }

    else if(temp == tail) {
        insertLast(data);
    }

    else {
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;

    }
    
}

void display() {

    node * temp;
    temp = head;

    printf("Printing forward...\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        // tail = temp;
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

    insertFirst(4);
    insertFirst(3);
    insertLast(5);
    insertLast(7);
    insertFirst(2);
    insert_at_position(1, 1);
    insert_at_position(6, 6);
    insert_at_position(8, 8);


    display();

    return 0;
}


/*

Output:

Printing forward...
1 2 3 4 5 6 7 8 
Printing backward...
8 7 6 5 4 3 2 1 

*/
