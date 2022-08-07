#include<stdio.h>
#include<stdlib.h>

int main() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    int row1, col1, row2, col2;
    printf("Enter Row number of first matrix: ");
    scanf("%d", &row1);
    
    printf("Enter Column number of first matrix: ");
    scanf("%d", &col1);

    printf("Enter Row number of second matrix: ");
    scanf("%d", &row2);

    printf("Enter Column number of second matrix: ");
    scanf("%d", &col2);

    if(row1 == row2  && col1 == col2) {
        int matrix_1[row1][col1];
    printf("Enter elements of Matrix 1: \n");
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            scanf("%d", &matrix_1[i][j]);
        }
    }

    int matrix_2[row2][col2];
    printf("Enter elements of Matrix 2: \n");
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < col2; j++) {
            scanf("%d", &matrix_2[i][j]);
        }
    }

    int matrix_sub[row1][col1];
    
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            matrix_sub[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
    }

    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            printf("%d ", matrix_sub[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    }
    else printf("Invalid input...\n");

    return 0;
}
