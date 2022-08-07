#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*top;

typedef struct Node node;

node * getNode() {
    return ((node*)malloc(sizeof(node)));
}

void push(int data) {
    node *temp = getNode();

    temp -> data = data;

    if(top == NULL) {
        top = temp;
        top -> next = NULL;
    }
    else {
        temp -> next = top;
        top = temp;
    }
}

void pop() {
    if(top == NULL) printf("Satck is Underflow!  Nothing to pop!\n");
    else {
        printf("poped : %d\n", top->data);
        top = top->next;
    }
}

void display() {
    if(top == NULL) printf("Stack Underflow!\n");
    else {
        node * temp;
        temp = top;
        printf("Stack : ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void peek() {
    if(top == NULL) printf("Stack Underflow\n");
    else printf("Last element : %d\n", top->data);
}

int main() {

    for(int i = 1; i <= 3; i++) push(i);
    display();
    pop();
    pop();
    pop();
    pop();
    display();
    push(10);
    push(100);
    push(1000);
    push(10000);
    display();
    peek();
    return 0;
}

/*

Output:

Stack : 3 2 1 
poped : 3
poped : 2
poped : 1
Satck is Underflow!  Nothing to pop!
Stack Underflow!
Stack : 10000 1000 100 10 
Last element : 10000

*/
