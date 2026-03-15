#include <stdio.h>
#include "matrix.h"

void inputMatrix(int matrix[10][10], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&matrix[i][j]);
}

void displayMatrix(int matrix[10][10], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int result[10][10], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtractMatrix(int a[10][10], int b[10][10], int result[10][10], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            result[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrix(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int c2)
{
    int i,j,k;

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            result[i][j] = 0;
            for(k=0;k<c1;k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transposeMatrix(int matrix[10][10], int result[10][10], int row, int col)
{
    int i,j;

    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            result[j][i] = matrix[i][j];
}

int determinant2x2(int matrix[10][10])
{
    return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
}

int determinant3x3(int matrix[10][10])
{
    int det;

    det = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1])
        - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0])
        + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);

    return det;
}