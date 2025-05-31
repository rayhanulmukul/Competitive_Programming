#include<stdio.h>

int main() 
{
    int n;
    printf("Enter The size of the Array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    // At first find the largest element...
    int largest = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] > largest) largest = a[i];
    }
    int second_largest = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] != largest) {
            if(a[i] > second_largest) second_largest = a[i];
        }
    }
    printf("Second Largest Element is : %d\n", second_largest);
    return 0;
}
