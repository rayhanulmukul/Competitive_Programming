// Merge two unsorted array...
#include<stdio.h>

int main() {
    int a[10], b[10], c[20];
    int n1, n2;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first array: ");
    for(int i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second array: ");
    for(int i = 0; i < n2; i++) scanf("%d", &b[i]);

    int m = n1+n2;

    int index = 0; 
    // copying first array...
    for(int i = 0; i < n1; i++) {
        c[index] = a[i];
        index++;
    }
    // copying second array...
    for(int i = 0; i < n2; i++) {
        c[index] = b[i];
        index++;
    }

    for(int i = 0; i < m; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}
