// Insert an element in a given position and an unsorted array

#include<stdio.h>

void print_array(int a[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void insert(int a[], int index, int value, int n) {
    for(int i = n-1; i >= index; i--) {
        a[i+1] = a[i];
    }
    a[index] = value;
}

int main()
{
    int a[10];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter elements of the array: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter the position where element will be added: ");
    int index;
    scanf("%d",&index);
    printf("Enter the value to be added on this position: ");
    int value;
    scanf("%d", &value);

    printf("Elements before inserting...\n");
    print_array(a, n);

    insert(a, index, value, n);
    n++;
    print_array(a, n);

    return 0;
    
}
