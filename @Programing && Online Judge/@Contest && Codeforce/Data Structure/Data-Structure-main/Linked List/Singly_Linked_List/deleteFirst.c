#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data; 
   struct Node * next;
} *head;

typedef struct Node node;

void display() {
    node * temp = head;
    if(head == NULL) {
        printf("Nothing to print\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertFirst(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void insertLast(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode-> data = item;
    newNode->next = NULL;

    if(head == NULL) head = newNode;
    else {
        node * temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

}

void insert_kth_position(int k, int item) 
{
    node * temp, *temp1;
    temp = (node *) malloc(sizeof(node));

    temp->data = item;

     if(head == NULL) {
        head = temp;
        head->next = NULL;
    }
    else if(k == 0) {
        temp->next = head;
        head = temp;
    }
    else {
        temp1 = head;
    while((k - 1) > 0) {
        temp1 = temp1->next;
        k--;
    }
    temp->next = temp1->next;
    temp1->next = temp;   
    } 
}

void deleteFirst()
{
    if(head == NULL) printf("Nothing to delete\n");
    else {
      head = head->next;
    }
}

int main()
{
    insertLast(553);
    insertLast(554);
    printf("After inserting at last: \n");
    display();

    insert_kth_position(0,550);
    insert_kth_position(1,551);
    insert_kth_position(2,552);

    printf("After inserting at kth position: \n");
    display();

    deleteFirst();

    printf("After deleting first element: \n");
    display();
    
    return 0;
}
