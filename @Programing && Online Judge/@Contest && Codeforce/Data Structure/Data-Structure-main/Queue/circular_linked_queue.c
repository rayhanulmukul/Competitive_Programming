#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*front, *rear;
typedef struct Node node;

int isEmpty() {
    return (rear == NULL && front == NULL);
}

void enqueue(int item) {

    node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode -> data = item;
    newNode -> next = front;

    if(rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear -> next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(isEmpty()) printf("Queue is Underflow!\n");
    else if(rear == front) {
        node *temp = front;
        front = rear = NULL;
        printf("Dequeued : %d\n", temp->data);
        free(temp);
    }
    else {
        node *temp = front;
        front = front -> next;
        rear -> next = front;
        printf("Dequeued : %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if(isEmpty()) printf("Nothing to print!  List is Underflow!\n");
    else {
        printf("Queue is : ");
        node *temp;
        temp = front;
        while(temp -> next != front) {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("%d", temp->data);
        printf("\n");
    }
}

int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();

    display();

    dequeue();

    display();

    enqueue(5);
    enqueue(6);

    display();
    
    return 0;
}


/*

Output:

Queue is : 1 2 3 4 5
Dequeued : 1
Queue is : 2 3 4 5
Dequeued : 2
Dequeued : 3
Dequeued : 4
Queue is : 5
Dequeued : 5
Nothing to print!  List is Underflow!
Queue is : 5 6

*/
