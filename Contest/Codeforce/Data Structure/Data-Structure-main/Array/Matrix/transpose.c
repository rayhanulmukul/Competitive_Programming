#include <stdio.h>
int main()
{
    int row, col, matrix[10][10], transposed[10][10];
    printf("Enter row and Column size : ");
    scanf("%d %d", &row, &col);
    printf("Enter the elements of matrix : \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    printf("Transposed matrix :\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Input: 

Enter row and Column size : 3 3
Enter the elements of matrix : 
1 2 3
4 5 6
7 8 9

Output: 

Transposed matrix :
1  4  7  
2  5  8  
3  6  9  

*/
