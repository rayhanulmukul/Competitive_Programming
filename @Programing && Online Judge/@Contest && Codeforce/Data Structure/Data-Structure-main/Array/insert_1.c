// Insert a number in a given a sorted array....

#include<stdio.h>

int main()
{
    int a[10];
    printf("Enter the size of the array : ");
    int n; 
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < 5; i++) scanf("%d", &a[i]);
    printf("Enter the elements to be inserted: ");
    int x;
    scanf("%d", &x);
    
    int i;
    for(i = 0; i < n; i++) {
        if(a[i] <= x) continue;
        else break;
    }
    
    for(int j = n-1; j >= i; j--) a[j+1] = a[j];
    a[i] = x;

    for(int i = 0; i <= n; i++) printf("%d ", a[i]);

    return 0; 
}
