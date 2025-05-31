#include<stdio.h>
#include<stdlib.h>

#define q_size 5
int queue[q_size];
int front = -1, rear = -1;

int isFull() {
    return rear == q_size-1;
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int item) {
    if(isFull()) printf("Queue is overflow!\n");

    else if(isEmpty()) {
        front = rear = 0;
        queue[rear]  = item;
    }
    else queue[++rear] = item;
}

void dequeue() {
    if(isEmpty()) printf("Queue is Underflow!\n");
    else if(front == rear) front = rear = -1;
    else {
        printf("Dequeued element is : %d\n", queue[front]);
        queue[++front];
    }
}

void display() {
    if(isEmpty()) printf("Queue is empty\n");
    else {
        for(int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int peek() {
    if(isEmpty()) return 0;
    return queue[front];
}


int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();
    printf("Front value is : %d\n", peek());
    return 0;
}
