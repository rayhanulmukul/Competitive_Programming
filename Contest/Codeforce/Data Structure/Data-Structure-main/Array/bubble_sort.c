#include<stdio.h>

void print_array(int a[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
}

void bubble_sort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of the array:");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("\nBefore sorting: ");
    print_array(a, n);

    bubble_sort(a, n);
    
    printf("\nAfter sorting: ");
    print_array(a, n);
    printf("\n");

    return 0;

}
