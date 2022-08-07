// Delete a number from an array that is already sorted in ascending order.....

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

    printf("Enter the number to be deleted: ");
    int x;
    scanf("%d", &x);

    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            for(int j = i; j < n; j++) a[j] = a[j+1];
            break;
        }
    }
    for(int i = 0; i < n-1; i++) printf("%d ", a[i]);    

    return 0;
}
