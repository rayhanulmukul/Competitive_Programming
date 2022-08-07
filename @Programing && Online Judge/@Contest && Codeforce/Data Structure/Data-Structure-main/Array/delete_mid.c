#include<stdio.h>

int main()
{
    int a[10];
    int n;
    printf("Enetr the size of the array: ");
    scanf("%d", &n);
    //int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    // for deleting middle number...
    int x = a[n/2];
    for(int i = n/2; i <= n; i++) a[i] = a[i+1];

    for(int i = 0; i < n-1; i++)
        printf("%d ", a[i]);
    printf("\nDeleted value: %d\n", x);

    return 0;
}
