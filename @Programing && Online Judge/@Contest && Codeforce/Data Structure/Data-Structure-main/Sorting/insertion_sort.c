#include <stdio.h>

void display(int a[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void insertion_sort(int a[], int size) {
  int j, key;
  for(int i = 1; i < size; i++) {
    key = a[i];
    j = i-1;
    while(j >= 0 && a[j] > key) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}

int main()
{
  int a[] = {54,68,92,12,3,54,18,76,52,89,14};
  int size = sizeof(a)/sizeof(a[0]);
  
  printf("Before sorting : ");
  display(a, size);
  
  insertion_sort(a, size);
  
  printf("After sorting : ");
  display(a, size);
  
  
  return 0;
}



/*

Output:

Before sorting : 54 68 92 12 3 54 18 76 52 89 14 
After sorting : 3 12 14 18 52 54 54 68 76 89 92

*/
