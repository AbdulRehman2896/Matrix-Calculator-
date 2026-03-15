#include "matrix.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    int a[10][10], b[10][10], result[10][10];
    float inverseResult[10][10];
    int r1, c1, r2, c2;
    int choice;

    clearScreen();
    printf("╔══════════════════════════╗\n");
    printf("║   Welcome to MatrixCalc  ║\n");
    printf("╚══════════════════════════╝\n");

    while (1) {

        printMenu();
        scanf("%d", &choice);

        if (choice == 0) {
            clearScreen();
            printf("\nGoodbye!\n");
            break;
        }

        clearScreen();

        // operations that need matrix A only
        if (choice >= 1 && choice <= 6) {
            inputMatrixPrompt((int *)a, &r1, &c1, 'A');
        }

        // operations that need matrix B
        if (choice == 1 || choice == 2 || choice == 3) {
            inputMatrixPrompt((int *)b, &r2, &c2, 'B');
        }

        switch (choice) {

        case 1:
            if (r1 != r2 || c1 != c2) {
                printf("\n[!] Matrices must be the same size for addition.\n");
                break;
            }
            addMatrix((int *)a, (int *)b, (int *)result, r1, c1);
            printf("\nResult:\n");
            displayMatrix((int *)result, r1, c1);
            break;

        case 2:
            if (r1 != r2 || c1 != c2) {
                printf("\n[!] Matrices must be the same size for subtraction.\n");
                break;
            }
            subtractMatrix((int *)a, (int *)b, (int *)result, r1, c1);
            printf("\nResult:\n");
            displayMatrix((int *)result, r1, c1);
            break;

        case 3:
            if (c1 != r2) {
                printf("\n[!] Columns of A must equal rows of B for multiplication.\n");
                break;
            }
            multiplyMatrix((int *)a, (int *)b, (int *)result, r1, c1, c2);
            printf("\nResult:\n");
            displayMatrix((int *)result, r1, c2);
            break;

        case 4:
            transposeMatrix((int *)a, (int *)result, r1, c1);
            printf("\nTranspose:\n");
            displayMatrix((int *)result, c1, r1);
            break;

        case 5:
            if (r1 != c1) {
                printf("\n[!] Determinant requires a square matrix.\n");
                break;
            }
            printf("\nDeterminant = %d\n", determinant((int *)a, r1));
            break;

        case 6:
            if (r1 != c1) {
                printf("\n[!] Inverse requires a square matrix.\n");
                break;
            }
            if (determinant((int *)a, r1) == 0) {
                printf("\n[!] Matrix is singular (determinant = 0), inverse does not exist.\n");
                break;
            }
            inverseMatrix(r1, c1, (int *)a, (float *)inverseResult);
            printf("\nInverse:\n");
            displayMatrixFloat((float *)inverseResult, r1, c1);
            break;

        default:
            printf("\n[!] Invalid choice, please try again.\n");
        }

        // pause so user can read result before screen clears
        printf("\n\nPress Enter to continue...");
        getchar();
        getchar();
        clearScreen();
    }

    return 0;
}