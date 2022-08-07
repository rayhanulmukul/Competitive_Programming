#include <stdio.h>

int binarySearch(int arr[], int l, int r, int item)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;
  
        // if item is at mid
        if (arr[mid] == item)
            return mid;
  
        if (arr[mid] < item)
            l = mid + 1;
  
        else
            r = mid - 1;
    }
  
    return -1;
}
  
int main(void)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int item = 30;
    
    int position = binarySearch(arr, 0, size - 1, item);
    
    if(position == -1)
        printf("%d Not Found",item);
    else
        printf("%d Found at index : %d",item, position);
        
    return 0;
}
