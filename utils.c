#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// print menu for the home screen
void printMenu() {
    printf("\n╔══════════════════════════╗\n");
    printf("║     MATRIX CALCULATOR    ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║  1. Addition             ║\n");
    printf("║  2. Subtraction          ║\n");
    printf("║  3. Multiplication       ║\n");
    printf("║  4. Transpose            ║\n");
    printf("║  5. Determinant          ║\n");
    printf("║  6. Inverse              ║\n");
    printf("║  0. Exit                 ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Enter choice: ");
}

// inputting prompt for entries of the matrix
void inputMatrixPrompt(int *mat, int *r, int *c, char name) {
    printf("\n┌─ Matrix %c ───────────────┐\n", name);

    printf("│ Rows: ");
    scanf("%d", r);

    printf("│ Cols: ");
    scanf("%d", c);

    printf("│\n");
    printf("│ Enter elements row by row:\n");
    inputMatrix(mat, *r, *c);

    printf("└──────────────────────────┘\n");
}