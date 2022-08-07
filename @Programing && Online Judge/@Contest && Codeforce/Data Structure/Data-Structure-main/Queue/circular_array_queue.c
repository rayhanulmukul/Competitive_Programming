#include<stdio.h>
#include<stdlib.h>

#define size 5
int queue[size];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear+1)%size == front);
}

void enqueue(int item) {
    if(isEmpty()) {
        front = rear = 0;
        queue[rear] = item;
    }
    else if(isFull()) printf("Queue is Full!\n");
    else {
        rear = (rear+1)%size;
        queue[rear] = item;
    }
}

void dequeue() {
    if(isEmpty()) printf("Nothing to dequeue...\n");
    else if(front == rear) {
      front = rear = -1;
    }
    else {
        int temp = front;
        printf("Dequeued Element is : %d\n", queue[temp]);
        front = (front+1)%size;
    }
}

void display() {
    if(isEmpty()) printf("Nothing in the queue\n");
    else {
        int i = front;
        printf("Queue is : ");
        while(i != rear) {
            printf("%d ", queue[i]);
            i = (i+1)%size;
        }
        printf("%d", queue[rear]);
        printf("\n");
    }
}

void peek() {
    if(isEmpty()) printf("Nothing in the queue\n");
    else printf("Front value of the queue : %d\n", queue[front]);
}

int main() {
    
    enqueue(5);
    enqueue(4);
    enqueue(3);
    
    display();
    
    dequeue();
    
    display();
    
    enqueue(6);
    
    dequeue();
    dequeue();
    
    enqueue(7);
    
    display();
    
    peek();
    
    dequeue();
    dequeue();
    
    display();
    
    dequeue();
    
    enqueue(100);
    enqueue(1000);
    
    dequeue();
    
    display();

    return 0;
}

/*

Output:

Queue is : 5 4 3
Dequeued Element is : 5
Queue is : 4 3
Dequeued Element is : 4
Dequeued Element is : 3
Queue is : 6 7
Front value of the queue : 6
Dequeued Element is : 6
Nothing in the queue
Nothing to dequeue...
Dequeued Element is : 100
Queue is : 1000

*/
