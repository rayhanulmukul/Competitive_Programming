#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data; 
   struct Node * next;
} *head;

typedef struct Node node;

void print() {
    node * temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void append(int item) {
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

int main()
{
    int n;
    printf("Enter the number of element to be inserting in last position: ");
    scanf("%d", &n);
    printf("Enter the elements to be inserted: ");
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        append(x);
    }

    printf("Printing the list: \n");

    print();

    return 0;
}
