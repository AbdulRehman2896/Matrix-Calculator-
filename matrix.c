#include "matrix.h"
#include <stdio.h>

// utility functions
void inputMatrix(int *matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        printf("  Row %d:\n", i + 1);
        for (int j = 0; j < col; j++) {
            printf("    Col %d: ", j + 1);
            scanf("%d", (matrix + i * col + j));
        }
    }
}

void displayMatrix(int *matrix, int r, int c) {

    printf("[\n");

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            printf("%d ", *(matrix + i * c + j));
        }
        printf("\n");
    }
    printf("]");
}

void displayMatrixFloat(float *matrix, int r, int c) {
    printf("[\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%.4f ", *(matrix + i * c + j));
        printf("\n");
    }
    printf("]\n");
}


// matrix operations addition, subtraction miltiplication, transpose, determinant
void addMatrix(int *a, int *b, int *result, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            *(result + i * col + j) = *(a + i * col + j) + *(b + i * col + j);
}

void subtractMatrix(int *a, int *b, int *result, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            *(result + i * col + j) = *(a + i * col + j) - *(b + i * col + j);
}

void multiplyMatrix(int *a, int *b, int *result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(result + i * c2 + j) = 0;
            for (int k = 0; k < c1; k++)
                *(result + i * c2 + j) += *(a + i * c1 + k) * *(b + k * c2 + j);
        }
    }
}

void transposeMatrix(int *matrix, int *result, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            *(result + j * row + i) = *(matrix + i * col + j);
}

int determinant(int *mat, int n) {

    // base case: 1x1 matrix
    if (n == 1) return *(mat + 0);

    // base case: 2x2 matrix
    if (n == 2)
        return *(mat + 0) * *(mat + 3) - *(mat + 1) * *(mat + 2);

    int det = 0;

    // expand along first row
    for (int j = 0; j < n; j++) {

        // build the minor matrix (size (n-1) x (n-1))
        int minorMat[(n-1) * (n-1)];
        int r = 0, c = 0;

        for (int x = 1; x < n; x++) {   // skip row 0
            c = 0;
            for (int y = 0; y < n; y++) {
                if (y == j) continue;    // skip column j
                minorMat[r * (n-1) + c] = *(mat + x * n + y);
                c++;
            }
            r++;
        }

        // sign * element * determinant of minor
        int sign = (j % 2 == 0) ? 1 : -1;
        det += sign * *(mat + j) * determinant(minorMat, n - 1);
    }

    return det;
}


// inverse of a matrix
// general interpretation is A inverse = 1/|A| * Adjoint(A), only 2x2 and 3x3
// matrices are handled


// calculate minor element of the matrix
static int minor(int i, int j, int *mat, int n, int rows, int cols) {
    int minorMat[(rows - 1) * (cols - 1)];
    int r = 0, c = 0;

    for (int x = 0; x < rows; x++) {
        if (x == i)
            continue;
        c = 0;
        for (int y = 0; y < cols; y++) {
            if (y == j)
                continue;
            minorMat[r * (cols - 1) + c] = *(mat + x * n + y);
            c++;
        }
        r++;
    }
    return determinant(minorMat, rows - 1);
}


// calculate co-factor
static int cofactor(int i, int j, int minorElement) {
    int sign = ((i + j) % 2 == 0) ? 1 : -1;
    return sign * minorElement;
}


// calculate adjoint
static void adjoint(int *mat, int n, int r, int c, float *adjOut) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int minorElement = minor(i, j, mat, n, r, c);
            int cofact = cofactor(i, j, minorElement);
            *(adjOut + j * n + i) = cofact; // transpose
        }
    }
}

// inverse calculator
void inverseMatrix(int r, int c, int *mat, float *inverseMat) {
    int detMat = determinant(mat, r);

    adjoint(mat, r, r, c, inverseMat);

    printf("Adjoint:\n");
    displayMatrixFloat(inverseMat, r, c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(inverseMat + i * c + j) /= detMat;
}