#include <stdio.h>

// Function to print array 
void display(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Main function to run the program
int main() 
{ 
    int array[] = {5, 3, 1, 9, 8, 2, 4,7}; 
    int size = sizeof(array)/sizeof(array[0]); 

    printf("Before bubble sort : ");
    display(array, size);

    int i, j, temp; 
    for (i = 0; i < size-1; i++){       

       // Since, after each iteration right-most i elements are sorted   
       for (j = 0; j < size-i-1; j++) 
           if (array[j] > array[j+1]) 
           {
              temp = array[j]; // swap the element
              array[j] = array[j+1]; 
              array[j+1] = temp; 
           }
    }
    printf("After bubble sort : "); 
    display(array, size); 
    return 0; 
}
