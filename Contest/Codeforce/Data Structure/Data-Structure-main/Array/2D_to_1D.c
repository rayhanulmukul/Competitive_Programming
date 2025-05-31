#include<stdio.h>
#include<stdlib.h>

int main() {
   
    int row, col;
    printf("Enter Row number: ");
    scanf("%d", &row);
    printf("Enter Column number: ");
    scanf("%d", &col);

    int arr_2D[row][col];
    printf("Enter elements: \n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &arr_2D[i][j]);
        }
    }

    int arr_1D[row*col];
    int size = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            arr_1D[size++] = arr_2D[i][j];
        }
    }

    printf("printing 1D Array\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr_1D[i]);
    }
    printf("\n");

    return 0;
}
