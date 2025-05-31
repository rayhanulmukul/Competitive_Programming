#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct node *next;
};

typedef struct Node node;
node *front, *rear;

int isEmpty() {
    return (front == NULL);
}

 void enqueue(int data) {
    node *newNode;
    newNode = (node *) malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty()) front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
 }

void dequeue() {
    if(isEmpty()) printf("Queue is Underflow!\n");
    else {
        node * temp = front;
        front = front -> next;

        printf("Dequeued Element is : %d\n", temp->data);
        free(temp);
    }
}
 void display() {
    if(isEmpty()) printf("Queue is Empty\n");
    else {
        node *temp = front;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
 }

void peek() {
    printf("Peeked element is : %d\n", front->data);
}

 int main() {
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(13);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();

    return 0;
 }


/*

Output:

10 11 12 13 
Dequeued Element is : 10
Dequeued Element is : 11
Dequeued Element is : 12
13 
Dequeued Element is : 13
Queue is Underflow!
Queue is Empty

*/
