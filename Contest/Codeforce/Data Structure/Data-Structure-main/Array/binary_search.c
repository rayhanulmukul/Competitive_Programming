// Binary search to a sorted array...

#include<stdio.h>

void print_array(int a[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int binary_search(int a[], int n, int x) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(a[mid] == x) return mid;
        else if(a[mid] > x) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elemetnts of the array: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter a value to search: ");
    int x;
    scanf("%d",&x);
    print_array(a, n);
    int index = binary_search(a, n, x);
    if(index == -1) printf("Not found!\n");
    else printf("%d Found at the position %d\n", x, index+1);

    return 0;

}
