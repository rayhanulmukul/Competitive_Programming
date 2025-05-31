#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void isEmpty();
void isFull();
void show();

int top = -1;
int size = 100;
int stack[100];

int main()
{

    while(1)
    {
        int choice;
        printf("\n\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4. isEmpty\n5. isFull\n6. End");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: show();
                    break;
            case 4: isEmpty();
                    break;
            case 5: isFull();
                    break;
            case 6: exit(0);

            default: printf("invalid choice!\n");

        }
    }

}
void push() 
    {
        int item;
        printf("Enter a value to push: \n");
        scanf("%d", &item);

        if(top == size-1) {
            printf("Stack is overflow!\n");
        }
        else {
            top += 1;
            stack[top] = item;
        }

    }

void pop()
{
    if(top == -1) {
        printf("stack is Underflow!\n");
    }
    else {
        printf("%d was popped!", stack[top--]);
    }
}

void show() {
    if(top == -1) {
        printf("stack underflow!\n");
    }
    else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void isEmpty()
{
    if(top == -1)
    {
        printf("stack is Empty!\n");
    }
    else {
        printf("stack is not empty! \n");
    }
}

void isFull()
{
    if(top == size-1)
    {
        printf("stack is Full!\n");
    }
    else {
        printf("stack is not full! \n");
    }
}
