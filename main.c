#include <stdio.h>
#include "matrix.h"

int main()
{
    int a[10][10], b[10][10], result[10][10];
    int r1,c1,r2,c2;
    int choice;
    int det;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d",&r1,&c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(a,r1,c1);

    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Transpose");
    printf("\n5. Determinant");
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    if(choice==1 || choice==2 || choice==3)
    {
        printf("Enter rows and columns of Matrix B: ");
        scanf("%d %d",&r2,&c2);

        printf("Enter elements of Matrix B:\n");
        inputMatrix(b,r2,c2);
    }

    if(choice==1)
    {
        addMatrix(a,b,result,r1,c1);
        displayMatrix(result,r1,c1);
    }

    else if(choice==2)
    {
        subtractMatrix(a,b,result,r1,c1);
        displayMatrix(result,r1,c1);
    }

    else if(choice==3)
    {
        multiplyMatrix(a,b,result,r1,c1,c2);
        displayMatrix(result,r1,c2);
    }

    else if(choice==4)
    {
        transposeMatrix(a,result,r1,c1);
        printf("Transpose Matrix:\n");
        displayMatrix(result,c1,r1);
    }

    else if(choice==5)
    {
        if(r1==2 && c1==2)
        {
            det = determinant2x2(a);
            printf("Determinant = %d\n",det);
        }

        else if(r1==3 && c1==3)
        {
            det = determinant3x3(a);
            printf("Determinant = %d\n",det);
        }

        else
        {
            printf("Determinant only implemented for 2x2 or 3x3 matrix\n");
        }
    }

    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}