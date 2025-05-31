#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;
node *head;

void insertBeg(int data) {
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    if(head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    node *currNode = head;
    while(currNode->next != head) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode -> next = head;

    head = newNode;
}

void display() {
    node *currNode;
    currNode = head;

    do {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }while(currNode != head);
}

int main() {
    insertBeg(6);
    insertBeg(5);
    insertBeg(4);
    insertBeg(3);
    insertBeg(2);
    insertBeg(1);
    display();
}
