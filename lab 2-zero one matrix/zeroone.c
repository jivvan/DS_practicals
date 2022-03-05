#include <stdio.h>

int main()
{
    int row1, col1, row2, col2, i, j, matrix1[100][100], matrix2[100][100], product[100][100];
    printf("Enter number of rows and columns of first matrix:\n");
    scanf("%d%d", &row1, &col1);
    printf("Enter first matrix rowwise:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            do
            {
                scanf("%d", &matrix1[i][j]);
                if ((matrix1[i][j] > 1) || (matrix1[i][j] < 0))
                {
                    printf("Enter zero or one only\n");
                }
            } while ((matrix1[i][j] > 1) || (matrix1[i][j] < 0));
        }
    }
    printf("Enter number of rows and columns of second matrix:\n");
    scanf("%d%d", &row2, &col2);
    if (col1 != row2)
    {
        printf("The two matrices cannot be multiplied\n");
        return 0;
    }
    printf("Enter second matrix rowwise:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            do
            {
                scanf("%d", &matrix2[i][j]);
                if ((matrix2[i][j] > 1) || (matrix2[i][j] < 0))
                {
                    printf("Enter zero or one only\n");
                }
            } while ((matrix2[i][j] > 1) || (matrix2[i][j] < 0));
        }
    }
    printf("The boolean product is:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                product[i][j] = product[i][j] || (matrix1[i][k] && matrix2[k][j]);
            }
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }
    return 0;
}