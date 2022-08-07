#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*head;
typedef struct Node node;

node * getNode() {
    node * temp;
    temp = (node*) malloc(sizeof(node));

    return temp;
}

int getCurrentSize() {
    node * temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

void insert(int item) {
    node * temp = getNode();

    temp -> data = item;
    temp -> next = NULL;

    if(head == NULL) head = temp;
    
    else {
        node * curr_node = head;

        while(curr_node -> next != NULL) curr_node = curr_node -> next;
        curr_node -> next = temp;
    }
}

void delete_nth_node(int pos) {

    if(pos == 1)
        head = head -> next;
    
    else {
        node * curr_node = head;
        node * prev = curr_node;
        while(--pos) {
            prev = curr_node;
            curr_node = curr_node -> next;
        }
        int deleted = curr_node -> data;
        printf("%dth node deleted...\n", deleted);
        prev -> next = curr_node -> next;
    }
    
}

void delete_an_item(int item) {
    node * temp = head;

    int count = 0;
    while(temp != NULL) {
        count++;
        if(temp -> data == item) break; 
        temp = temp -> next;
        
    }
    if(count > getCurrentSize() || count == 0) {
        printf("item doesn't exist...\n");
    }
    else {
        delete_nth_node(count);
        printf("%d deleted...\n", item);
    }

}

void show() {
    node * temp = head;

    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}



int main() 
{
    int size;

    for(int i = 1; i <= 10; i++) insert(i);
    show();
    
    size = getCurrentSize();
    printf("Current size: %d\n", size);

    // delete_nth_node(5);
    // show();

    delete_an_item(10);
    show();

    size = getCurrentSize();
    printf("Current size: %d\n", size);

    return 0;
}
