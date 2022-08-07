#include<stdio.h>
#include<string.h>
int main()
{
    int row1, row2, col1, col2;
    printf("Enter the row and column of first matrix: ");
    scanf("%d %d", &row1, &col1);
    int matrix1[row1][col1];

    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the row and column of second matrix: ");
    scanf("%d %d", &row2, &col2);
    int  matrix2[row2][col2];
    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    int matrix3[row1][col2];
    memset(matrix3, 0, sizeof(matrix3));
    if(col1 == row2) {
    // playing multiplication....
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            for(int k = 0; k < row2; k++) {
                matrix3[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }

    printf("result = \n");

    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    }
    else printf("Matrix multiplication is not possible...!\n");


    return 0;
}
